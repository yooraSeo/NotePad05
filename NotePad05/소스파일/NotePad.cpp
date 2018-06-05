/*
파일명 : NotePad.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : 노트패드 CFrameWnd 정의(CREATE,PAINT,CLOSE)
수정 : factory method pattern 적용
*/
//NotePad.cpp
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"
#include "Composite.h"
#include "CharacterMatrix.h"
#include "CaretController.h"
#include "CharacterMatrixSingletonPattern.h"
#include "GlyphFactory.h"
#include "SaveFile.h"
#include "LoadFile.h"
#include "KeyAction.h"
#include "MouseAction.h"
#include "Positioner.h"
#include "Range.h"
#include "ActionCreator.h"
#include "PaintVisitor.h"
#include "Range.h"
#include "Reverse.h"
#include "IntervalKeyAction.h"
#include "RangeDelete.h"
#include <string>
#include <string.h>
#include <afxwin.h>
#include "IntervalActionCreator.h"

using namespace std;
BEGIN_MESSAGE_MAP(NotePad, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_MESSAGE(WM_IME_CHAR, OnImeChar)
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
	ON_MESSAGE(WM_IME_STARTCOMPOSITION, OnImeStartComposition)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_CLOSE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


NotePad::NotePad() {
	CString name = "새메모장";
	this->name = (LPCTSTR)name;
	this->paper = NULL;
	this->line = NULL;
	this->caretController = NULL;
	this->glyphFactory = NULL;
	this->mouseAction = NULL;
	this->isComposition = FALSE;
	this->isDragging = FALSE;
	this->cursorPoint = NULL;
	this->positioner = NULL;
	this->range = NULL;
}

int NotePad::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->characterMatrix = CharacterMatrixSingletonPattern::Instance(this);
	this->glyphFactory = new GlyphFactory;
	this->paper = this->glyphFactory->FactoryCreator(0);
	LoadFile load = LoadFile(this, this->name);
	
	this->line = this->paper->GetAt(this->paper->GetCurrent());
	this->caretController = new CaretController(this);
	if (this->line->GetCurrent() < this->line->GetLength()) {
		this->line->Next(); // 로딩시 커런트의 입력 대기 위치 잡기
	}
	this->mouseAction = new MouseAction(this);
	this->positioner = new Positioner();
	this->range = new Range(this);
	this->reverse = 0;
	this->Notify();
	return 0;
}

void NotePad::OnPaint() {
	CPaintDC dc(this);
	PaintVisitor paintVisitor(&dc,this);
	this->paper->Accept(paintVisitor);

	if (this->GetIsRange() == TRUE) {
		if (this->reverse != 0) {
			this->reverse->ReverseDrow(this->range);
		}
		else {
			this->reverse = new Reverse(&dc, this);
			this->reverse->ReverseDrow(this->range);
		}
	}
	else {
		if (this->reverse != NULL) {
			this->reverse = 0;
		}
	}
	
	CString cstr;
	cstr.Format("줄 : %d, 칸 : %d, x : %d, y : %d,  마우스x : %d, 마우스y : %d,  범위 : %d",
		this->paper->GetCurrent() + 1, this->line->GetCurrent() + 1,
		this->GetCaretPos().x, this->GetCaretPos().y, this->GetCursorPoint().x, this->GetCursorPoint().y, this->GetIsRange());
	dc.TextOut(600, 80, CString(cstr)); //출력
}

BOOL NotePad::OnEraseBkgnd(CDC* pDC) {
	return TRUE;
}

void NotePad::OnClose() {
	CString name;
	this->GetWindowText(name);
	SaveFile saveFile((LPCTSTR)name,this->paper);
	if (glyphFactory != NULL) {
		delete glyphFactory;
		glyphFactory = NULL;
	}
	if (this->caretController != 0) {
		this->caretController = 0;
	}
	if (this->paper != 0) {
		delete this->paper;
	}
	
	CFrameWnd::OnClose();
}

void NotePad::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	ActionCreator actionCreator;
	KeyAction* keyAction = actionCreator.Create(this, nChar);
	IntervalActionCreator intervalActionCreator;
	IntervalKeyAction* intervalKeyAction = intervalActionCreator.Create(this, nChar);


	if (keyAction) {
		if (GetKeyState(VK_SHIFT) & 0x8000 && this->GetIsRange() == FALSE) {
			this->range = new Range(this);
			this->isRange = TRUE;
			if (GetKeyState(VK_CONTROL) & 0x8000) {
				if (intervalKeyAction != NULL) {
					intervalKeyAction->IntervalAction();
				}
			}
			else {
				keyAction->Action();
			}
			this->range->Sum(this);
		}
		else if (GetKeyState(VK_SHIFT) & 0x8000 && this->GetIsRange() == TRUE) {
			if (GetKeyState(VK_CONTROL) & 0x8000) {
				if (intervalKeyAction != NULL) {
					intervalKeyAction->IntervalAction();
				}
			}
			else {
				keyAction->Action();
			}
			this->range->Sum(this);
		}
		else if (this->isRange == TRUE && nChar == VK_BACK || this->isRange == TRUE && nChar == VK_DELETE) {
			RangeDelete* rangeDelete = new RangeDelete(this, this->range);
			this->isRange = FALSE;
			if (this->range != 0) {
				this->range = 0;
			}
		}
		else {
			if (GetKeyState(VK_CONTROL) & 0x8000) {
				if (intervalKeyAction != NULL) {
					intervalKeyAction->IntervalAction();
				}
			}
			else {
				keyAction->Action();
			}
			this->isRange = FALSE;
			if (this->range != 0) {
				this->range = 0;
			}
		}

	}
	this->Notify();
	this->Invalidate();
}

void NotePad::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {

	if (this->isRange != FALSE) {
		this->isRange = FALSE;
	}
	Long index;
	char characters[2];
	characters[0] = (char)nChar;
	characters[1] = 0;

	Glyph* glyph = this->glyphFactory->FactoryCreator(characters);
	if (nChar != VK_TAB && nChar != VK_RETURN && nChar != VK_ESCAPE && nChar != VK_BACK && nChar != 1) {
		if (this->line->GetCurrent() >= this->line->GetLength()) {
			this->line->Add(glyph);
			this->line->Next();
		}
	}
	if (nChar == VK_RETURN) {
		if (this->line->GetCurrent() >= this->line->GetLength() && this->paper->GetCurrent() >= this->paper->GetLength()-1) {
			index = this->paper->Add(glyph);
			this->line = this->paper->GetAt(index);
		}
	}
	else if (nChar == VK_TAB) {
		Long column = 10;
		Long i = line->GetCurrent() % 10;
		while (i < column) {
			this->line->Add(new SingleByteCharacter('\t'));
			i++;
		}
		line->Next();
	}
	else if (nChar == 1) {  //control key & a key 입력 = 전체선택
		Long row = this->paper->First();
		this->line = this->paper->GetAt(row);
		this->line->First();

		if (this->range != NULL) {
			this->range = NULL;
		}
		this->range = new Range(this);
		if (this->isRange != TRUE) {
			this->isRange = TRUE;
		}
		this->paper->Last();
		row = this->paper->Prev();
		this->line = this->paper->GetAt(row);
		this->line->Last();
		this->range->Sum(this);
	}
	if (this->isComposition != FALSE) {
		this->isComposition = FALSE;
	}
	this->Notify();
	this->Invalidate();
}

LRESULT NotePad::OnImeChar(WPARAM wParam, LPARAM lParam) {
	if (this->isRange != FALSE) {
		this->isRange = FALSE;
	}
	char nChar[2];
	Glyph* glyph;
	if (IsDBCSLeadByte((BYTE)(wParam >> 8)) == TRUE) {
		nChar[0] = HIBYTE(LOWORD(wParam));
		nChar[1] = LOBYTE(LOWORD(wParam));
		glyph = this->glyphFactory->FactoryCreator(nChar);
	}
	else {
		nChar[0] = (char)wParam;
		nChar[1] = 0;
		glyph = this->glyphFactory->FactoryCreator(nChar);
	}
	this->line->Remove(this->line->GetCurrent());
	this->line->Add(glyph);//(new DoubleByteCharacter(nChar));
	this->line->Next();
	this->isComposition = FALSE;
	
	this->Notify();
	this->Invalidate();

	return 0;
}

LRESULT NotePad::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	if (this->isRange != FALSE) {
		this->isRange = FALSE;
	}
	TCHAR nChar[2];
	Glyph* glyph;

	if (lParam & GCS_COMPSTR) {
		nChar[0] = HIBYTE(LOWORD(wParam));
		nChar[1] = LOBYTE(LOWORD(wParam));
		if (this->line->GetLength() > 0 && this->isComposition == TRUE) {
			this->line->Remove(this->line->GetCurrent());
		}
		if (nChar[0] != '\0') {
			glyph = this->glyphFactory->FactoryCreator(nChar);
			this->line->Add(glyph);
			this->isComposition = TRUE;
		}
		else {
			this->line->Next();
			this->isComposition = FALSE;
		}
		this->Invalidate(FALSE);
	}
	
	this->Notify();
	return ::DefWindowProc(this->m_hWnd, WM_IME_COMPOSITION, wParam, lParam);
}

LRESULT NotePad::OnImeStartComposition(WPARAM wParam, LPARAM lParam) {
	return 0;
}

void NotePad::OnSetFocus(CWnd* pOldWnd) {
	if (this->caretController == NULL) {
		this->caretController = new CaretController(this);
	}
	this->Notify();
	this->Invalidate(FALSE);
}

void NotePad::OnKillFocus(CWnd* pNewWnd) {
	if (this->caretController != NULL) {
		this->Delete(this->caretController);
		this->caretController = NULL;
	}
	if (this->isRange != FALSE) {
		this->isRange = FALSE;
	}
	
}

void NotePad::OnLButtonDown(UINT nFlags, CPoint point) {
	CPoint ret;
	CClientDC pDC(this);

	switch (nFlags)
	{
	case MK_LBUTTON:
		if (this->GetIsRange() != FALSE) {
			this->isRange = FALSE;
		}
		ret = this->mouseAction->Move(nFlags, point);
		break;
	case 5://쉬프트클릭
		if (this->GetIsRange() == TRUE) {
			ret = this->mouseAction->Move(nFlags, point);
			this->range->Sum(this);
		}
		else if (this->GetIsRange() == FALSE) {
			this->range = new Range(this);
			this->isRange = TRUE;
			ret = this->mouseAction->Move(nFlags, point);
			this->range->Sum(this);
		}
		break;
	default:
		break;
	}
	char cha = (char)this->GetLine()->GetAt(this->GetLine()->GetCurrent());
	Long code = cha;

	this->isDragging = TRUE;
	SetCapture();
	this->Notify();
	this->Invalidate();
	
}
void NotePad::OnLButtonUp(UINT nFlags, CPoint point) {
	this->isDragging = FALSE;
	this->cursorPoint = this->mouseAction->Move(nFlags, point);
	ReleaseCapture();
	if (this->isRange == TRUE) {
		Line* line = (Line*)this->GetLine();
		line->SetCurrent(this->range->GetEndColumn());
		this->SetLine(line);
	}
	this->Notify();
	this->Invalidate();
}

void NotePad::OnLButtonDblClk(UINT nFlags, CPoint point) {
	if (this->isRange == FALSE) {
		this->range = new Range(this);
		this->isRange = TRUE;
	}
	this->mouseAction->DoubleClicked(this, this->range);
}

void NotePad::OnMouseMove(UINT nFlags, CPoint point) {
	if (this->isDragging == TRUE) {
		if (this->GetIsRange() != FALSE) {
			this->cursorPoint = this->mouseAction->Move(nFlags, point);
			this->range->Sum(this);
		}
		else {
			this->range = new Range(this);
			this->isRange = TRUE;
			this->cursorPoint = this->mouseAction->Move(nFlags, point);
			this->range->Sum(this);
		}
		this->Invalidate(FALSE);
	}
}
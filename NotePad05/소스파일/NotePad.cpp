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


#include <string>
#include <string.h>
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
END_MESSAGE_MAP()


NotePad::NotePad() {
	CString name = "새메모장";
	//name.LoadString(AFX_IDS_APP_TITLE);
	//앱 타이틀 가져오기
	//this->GetWindowText(name);
	//현제 사용중인 윈도우 타이틀 가져오기
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
	if (this->line->GetCurrent() < this->line->GetLength()) {
		this->line->Next(); // 로딩시 커런트의 입력 대기 위치 잡기
	}
	this->Notify();
	this->mouseAction = new MouseAction(this);
	this->positioner = new Positioner();
	this->range = new Range;
#if 0
	position = line->Add(new SingleByteCharacter('1'));
	position = line->Add(new SingleByteCharacter('2'));
	position = line->Add(new SingleByteCharacter('3'));
	strcpy(kor, "한");
	position = line->Add(new DoubleByteCharacter(kor));
	strcpy(kor, "국");
	position = line->Add(new DoubleByteCharacter(kor));
	index = this->paper->Add(new Line);
	Glyph* lineTwo = paper->GetAt(index);
	position = lineTwo->Add(new SingleByteCharacter('A'));
	position = lineTwo->Add(new SingleByteCharacter('a'));
	position = lineTwo->Add(new SingleByteCharacter('B'));
	position = lineTwo->Add(new SingleByteCharacter('b'));
#endif

	////창 생성시 폰트 적용
	//this->font.CreateFont(26, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	//	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
	//font.CreateFont( //폰트 설정
	//	12,                        // nHeight
	//	12,                         // nWidth
	//	0,                         // nEscapement
	//	0,                         // nOrientation
	//	FW_NORMAL,                 // nWeight
	//	FALSE,                     // bItalic
	//	FALSE,                     // bUnderline
	//	0,                         // cStrikeOut
	//	ANSI_CHARSET,              // nCharSet
	//	OUT_DEFAULT_PRECIS,        // nOutPrecision
	//	CLIP_DEFAULT_PRECIS,       // nClipPrecision
	//	DEFAULT_QUALITY,           // nQuality
	//	DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	//	NULL);// _T("Arial"));                 // lpszFacename
	//

	return 0;
}

void NotePad::OnPaint() {
	CPaintDC dc(this);
	this->GetFont();
	CFont *pOldFont = dc.SelectObject(&this->font); //만든 폰트 적용	
	//CFont font = this->GetFont;
	
	PaintVisitor paintVisitor(&dc,this);
	this->paper->Accept(paintVisitor);

	
	line = paper->GetAt(paper->GetCurrent());
	CString cstr;
	cstr.Format("줄 : %d, 칸 : %d, x : %d, y : %d,  마우스x : %d, 마우스y : %d,  조합 : %d",
		paper->GetCurrent() + 1, line->GetCurrent() + 1,
		this->GetCaretPos().x, this->GetCaretPos().y, this->GetCursorPoint().x, this->GetCursorPoint().y, this->GetIsDragging());
	dc.TextOut(600, 80, CString(cstr)); //출력
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
	font.DeleteObject();
	CFrameWnd::OnClose();
}

void NotePad::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar == VK_HOME || nChar == VK_END || nChar == VK_LEFT || nChar ==VK_RIGHT || nChar ==VK_UP || nChar ==VK_DOWN || nChar== VK_PRIOR || nChar == VK_NEXT || nChar ==VK_BACK || nChar ==VK_DELETE || nChar==VK_ESCAPE) {
		ActionCreator actionCreator;
		KeyAction* keyAction = actionCreator.Create(this, nChar);
		keyAction->Action();
	}

	this->Invalidate();
}

void NotePad::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long index;
	char characters[2];
	characters[0] = (char)nChar;
	characters[1] = 0;

	Glyph* glyph = this->glyphFactory->FactoryCreator(characters);
	if (nChar != VK_TAB && nChar != VK_RETURN && nChar != VK_ESCAPE && nChar != VK_BACK) {
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
		Long i = 0;
		while (i < 8) {
			this->line->Add(new SingleByteCharacter(' '));
			i++;
		}
	}
	if (this->isComposition != FALSE) {
		this->isComposition = FALSE;
	}
	this->Notify();
	this->Invalidate(FALSE);
}

LRESULT NotePad::OnImeChar(WPARAM wParam, LPARAM lParam) {
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
	this->Invalidate(FALSE);

	return 0;
}

LRESULT NotePad::OnImeComposition(WPARAM wParam, LPARAM lParam) {

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
		this->Invalidate();
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
	this->Invalidate();
}

void NotePad::OnKillFocus(CWnd* pNewWnd) {
	if (this->caretController != NULL) {
		delete this->caretController;
		this->caretController = NULL;
	}
}

void NotePad::OnLButtonDown(UINT nFlags, CPoint point) {
	CPoint ret;
	
	switch (nFlags)
	{
	case MK_LBUTTON:
		//ret = this->mouseAction->Clicked(nFlags, point);
		//this->isDragging = TRUE;
		//SetCapture();
		////if (point.x < this->cursorPoint.x) {
		//CClientDC *pDC;
		////CRect rect(point, point);
		//CBrush curBrush(RGB(0, 0, 255));
		//CBrush *oldBrush;
		//oldBrush = pDC->SelectObject(&curBrush);
		//pDC->DrawDragRect(CRect(100,100,200,200),CSize(5,5),CRect(200,200,300,300),CSize(5,5),&curBrush,NULL);
		////}
		//this->Invalidate();
		ret = this->mouseAction->Clicked(nFlags, point);
		this->isDragging = TRUE;
		SetCapture();
		//this->cursorPoint = point;
		//if (this->line->GetCurrent() != 0) {
		//	CClientDC dc(this);
		//	CPen pen;
		//	pen.CreatePen(PS_DOT, 3, RGB(54, 138, 255));
		//	CPen* oldPen = dc.SelectObject(&pen);
		//	CBrush brush;
		//	brush.CreateSolidBrush(RGB(54, 138, 255));
		//	CBrush* oldBrush = dc.SelectObject(&brush);

		//	//dc.Rectangle(this->positioner->GetX(this, this->line, this->line->GetCurrent()), this->positioner->GetY(this, this->paper->GetCurrent()), this->positioner->GetX(this, this->line, this->line->GetCurrent()) + 2, this->positioner->GetY(this, this->paper->GetCurrent()) + this->characterMatrix->GetHeigh());
		//	
		//	dc.SelectObject(oldPen);
		//	dc.SelectObject(oldBrush);
		//}
		//this->Invalidate();
		
			//CPen pen;
			//pen.CreatePen(PS_DOT, 3, RGB(255, 0, 0));    // 빨간색 펜을 생성
			//CPen* oldPen = dc.SelectObject(&pen);

			//CBrush brush;
			//brush.CreateSolidBrush(RGB(255, 128, 0));     // 오렌지색 채움색을 생성
			//CBrush* oldBrush = dc.SelectObject(&brush);

			// 굵기가 3인 빨간색 펜을 유지하면서, 녹색으로 내부를 채우는 사각형을 그린다.
			//brush.DeleteObject();  // 오렌지색 브러시를 삭제
			//brush.CreateSolidBrush(RGB(0, 255, 0));       // 녹색 채움색을 생성
			//oldBrush = dc.SelectObject(&brush);

			//dc.Rectangle(point.x + 30, point.y + 30, point.x + 60, point.y + 60);

			//dc.SelectObject(oldPen);     // 시스템 펜 객체를 돌려줌

			//dc.SelectObject(oldBrush);    // 시스템 브러시 객체를 돌려줌

		//CClientDC dc(this);


		//dc.SetTextColor(RGB(255,0, 0));
		//dc.SetBkColor(RGB(0, 0, 0));


		//dc.SetBkMode(TRANSPARENT);   // 텍스트 배경을 투명하게 설정
		//dc.TextOut(point.x, point.y, CString("아놔아아아아아아아앙"));


		//dc.SetBkMode(OPAQUE);            // 텍스트 배경을 SetBkColor 사용
		//dc.TextOut(point.x, point.y + 20, CString("TEXT"));



		//dc.DrawText(CString("아놔"),CRect(point.x, point.y, point.x+20 , point.y+200), DT_CENTER);

		CClientDC pDC(this);
			//ASSERT_VALID(pDoc);

			//pDC.SetTextColor(RGB(255, 0, 0));
			//pDC.SetBkColor(RGB(128, 255, 255));
			//pDC.ExtTextOut(point.x, point.y, ETO_OPAQUE, CRect(point.x, point.y, point.x+this->characterMatrix->GetWidths(28)*13, point.y+this->characterMatrix->GetHeigh()), "Johnny Carson", 13, NULL);
	


		


		


		break;
	//default:
	//	break;
	}
	
}
void NotePad::OnLButtonUp(UINT nFlags, CPoint point) {
	//this->range->MouseDrow(this, &point);
	this->isDragging = FALSE;
	ReleaseCapture();
	this->Invalidate();
}
void NotePad::OnLButtonDulClk(UINT nFlags, CPoint point) {

}
void NotePad::OnMouseMove(UINT nFlags, CPoint point) {

	this->line->SetCurrent(point.x);
	//Invalidate();
	if (this->isDragging == TRUE) {
		//this->range->MouseDrow(this, &point);
		Invalidate(FALSE);
		//if (this->line->GetLength() != 0 && point.x < this->cursorPoint.x && point.y <= this->cursorPoint.y) {
		//	CClientDC dc(this);
		//	CPen pen;
		//	pen.CreatePen(PS_INSIDEFRAME, 0, RGB(54, 138, 255));
		//	CPen* oldPen = dc.SelectObject(&pen);
		//	CBrush brush;
		//	brush.CreateSolidBrush(RGB(54, 138, 255));
		//	CBrush* oldBrush = dc.SelectObject(&brush);
		//	//dc.Rectangle(point.x, point.y, point.x + this->characterMatrix->GetHangleWidth(), point.y + this->characterMatrix->GetHeigh());
		//	Long x = this->positioner->GetX(this, this->line, this->positioner->GetColumn(this, this->line, point.x));
		//	Long y = this->positioner->GetY(this, this->paper->GetCurrent());
		//	Long z = this->positioner->GetX(this, this->line, this->line->GetCurrent()-1) + this->characterMatrix->GetWidths(32);
		//	Long a = this->positioner->GetY(this, this->paper->GetCurrent()) + this->characterMatrix->GetHeigh();
		//	dc.Rectangle(x, y, z, a);
		//	dc.SetTextColor(RGB(255, 255, 255));
		//	dc.SetBkMode(TRANSPARENT);
		//	//dc.TextOut(point.x, point.y, CString("b"));
		//	//dc.DrawText(CString("아놔아아아아아앙"), CRect(x, y, z, a), DT_CENTER);
		//	dc.SelectObject(oldPen);
		//	dc.SelectObject(oldBrush);
		//}
		//else if (this->line->GetLength() != 0 && point.x > this->cursorPoint.x && point.y >= this->cursorPoint.y) {
		//	CClientDC dc(this);
		//	CPen pen;
		//	pen.CreatePen(PS_INSIDEFRAME, 0, RGB(54, 138, 255));
		//	CPen* oldPen = dc.SelectObject(&pen);
		//	CBrush brush;
		//	brush.CreateSolidBrush(RGB(54, 138, 255));
		//	CBrush* oldBrush = dc.SelectObject(&brush);
		//	//dc.Rectangle(point.x, point.y, point.x + this->characterMatrix->GetHangleWidth(), point.y + this->characterMatrix->GetHeigh());
		//	Long x = this->positioner->GetX(this, this->line, this->positioner->GetColumn(this, this->line, point.x));
		//	Long y = this->positioner->GetY(this, this->paper->GetCurrent());
		//	Long z = this->positioner->GetX(this, this->line, this->line->GetCurrent()) + this->characterMatrix->GetWidths(32);
		//	Long a = this->positioner->GetY(this, this->paper->GetCurrent()) + this->characterMatrix->GetHeigh();
		//	dc.Rectangle(x, y, z, a);
			//if (this->cursorPoint.y < point.y) {
			//	Long line = this->positioner->GetRow(this, point.y);
			//	x = this->positioner->GetX(this, this->paper->GetAt(line), this->positioner->GetColumn(this, this->paper->GetAt(line), point.x));
			//	y = this->positioner->GetY(this, line);
			//	z = this->positioner->GetX(this, this->paper->GetAt(line), this->positioner->GetColumn(this, this->paper->GetAt(line), point.x) + this->characterMatrix->GetWidths(32));
			//	a = this->positioner->GetY(this, line + this->characterMatrix->GetHeigh());
			//	dc.Rectangle(x, y, z, a);
			//}
		//	
		//	dc.SelectObject(oldPen);
		//	dc.SelectObject(oldBrush);
		//}
	}
		
	    //this->cursorPoint = point;

}
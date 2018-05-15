/*
���ϸ� : NotePad.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : ��Ʈ�е� CFrameWnd ����(CREATE,PAINT,CLOSE)
���� : factory method pattern ����
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
#include <string>
#include <string.h>
#include "GlyphFactory.h"
#include "SaveFile.h"
#include "LoadFile.h"
#include "KeyAction.h"
#include "MouseAction.h"

using namespace std;
BEGIN_MESSAGE_MAP(NotePad, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_MESSAGE(WM_IME_CHAR, OnImeChar)
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
	ON_MESSAGE(WM_IME_STARTCOMPOSITION, OnImeStartComposition)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


NotePad::NotePad() {
	CString name = "���޸���";
	//name.LoadString(AFX_IDS_APP_TITLE);
	//�� Ÿ��Ʋ ��������
	//this->GetWindowText(name);
	//���� ������� ������ Ÿ��Ʋ ��������
	this->name = (LPCTSTR)name;
	this->paper = NULL;
	this->line = NULL;
	this->caretController = NULL;
	this->isComposition = FALSE;
	this->glyphFactory = NULL;
	this->keyAction = NULL;
	this->mouseAction = NULL;
}

int NotePad::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->characterMatrix = CharacterMatrixSingletonPattern::Instance(this);
	this->glyphFactory = new GlyphFactory;
	this->paper = this->glyphFactory->FactoryCreator(0);
	LoadFile load = LoadFile(this, this->name);
	this->line = this->paper->GetAt(this->paper->GetCurrent());
	if (this->line->GetCurrent() < this->line->GetLength()) {
		this->line->Next(); // �ε��� Ŀ��Ʈ�� �Է� ��� ��ġ ���
	}
	this->Notify();
	this->keyAction = new KeyAction(this);
	this->mouseAction = new MouseAction(this);


#if 0
	position = line->Add(new SingleByteCharacter('1'));
	position = line->Add(new SingleByteCharacter('2'));
	position = line->Add(new SingleByteCharacter('3'));
	strcpy(kor, "��");
	position = line->Add(new DoubleByteCharacter(kor));
	strcpy(kor, "��");
	position = line->Add(new DoubleByteCharacter(kor));
	index = this->paper->Add(new Line);
	Glyph* lineTwo = paper->GetAt(index);
	position = lineTwo->Add(new SingleByteCharacter('A'));
	position = lineTwo->Add(new SingleByteCharacter('a'));
	position = lineTwo->Add(new SingleByteCharacter('B'));
	position = lineTwo->Add(new SingleByteCharacter('b'));
#endif

	////â ������ ��Ʈ ����
	//this->font.CreateFont(26, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
	//	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial"));
	//font.CreateFont( //��Ʈ ����
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
	Long row;
	Long i = 0;
	string text;
	//Glyph* line;
	Long height;
	row = this->paper->GetLength();
	CPaintDC dc(this);
	this->GetFont();
	CFont *pOldFont = dc.SelectObject(&this->font); //���� ��Ʈ ����	
	//CFont font = this->GetFont;
	Long num; //���� ���� �Ǽ�
	char cha[20];
	while (i < row) {
		this->line = this->paper->GetAt(i);
		text = this->line->MakeString();
		height = this->characterMatrix->GetHeigh();
		dc.TextOut(0, (i * height), CString(text.c_str()));
		
		CSize display_size = dc.GetTextExtent(text.c_str()); //ȭ�鿡 ������ ���ڿ��� ���� ���ϱ�
		num = display_size.cx; //���ڿ��� �Ǽ��� ����
		this->line = paper->GetAt(paper->GetCurrent());

		i++;
	}
	CString cstr; //ȭ�鿡 ����� ���ڿ�
	cstr.Format("�� : %d, ĭ : %d, x : %d, y : %d,     ���� : %d",
		paper->GetCurrent() + 1, this->line->GetCurrent() + 1,
		this->GetCaretPos().x, this->GetCaretPos().y, this->isComposition);
	dc.TextOut(600, 80, CString(cstr)); //���
	//GetConsoleCursorInfo()
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
	CPoint point;
	switch (nChar)
	{
	case VK_PRIOR:
		point = this->keyAction->Priorkey(nChar);
		break;
	case VK_NEXT:
		point = this->keyAction->NextKey(nChar);
		break;
	case VK_HOME:
		point = this->keyAction->HomeKey(nChar);
		break;
	case VK_END:
		point = this->keyAction->EndKey(nChar);
		break;
	case VK_LEFT:
		point = this->keyAction->LeftKey(nChar);
		break;
	case VK_RIGHT:
		point = this->keyAction->RightKey(nChar);
		break;
	case VK_UP:
		point = this->keyAction->UpKey(nChar);
		break;
	case VK_DOWN:
		point = this->keyAction->DownKey(nChar);
		break;
	case VK_BACK:
		point = this->keyAction->BackspaceKey(nChar);
		break;
	default: break;
	}
	Invalidate();
}

void NotePad::OnLButtonDown(UINT nFlags, CPoint point) {
	if (nFlags == MK_LBUTTON) {
		this->mouseAction->Clicked(point);
	}
	Invalidate();
}

void NotePad::OnLButtonUp(UINT nFlags, CPoint point) {

}

void NotePad::OnLButtonDblClk(UINT nFlags, CPoint point) {

}

void NotePad::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long index;
	char characters[2];
	characters[0] = (char)nChar;
	characters[1] = 0;
	Glyph* glyph = this->glyphFactory->FactoryCreator(characters);
	if (nChar != VK_TAB && nChar != VK_RETURN && nChar != VK_ESCAPE && nChar!=VK_BACK) {
		this->line->Add(glyph);
		this->line->Next();
	}
	else if (nChar == VK_RETURN) {
		index = this->paper->Add(glyph);
		this->line = this->paper->GetAt(index);
	}
	else if (nChar == VK_TAB) {
		Long i = 0;
		while (i < 8) {
			this->line->Add(new SingleByteCharacter(' '));
			i++;
		}
	}
	else if (nChar == VK_ESCAPE) {
		this->isComposition = FALSE;
	}
	if (this->isComposition != FALSE) {
		this->isComposition = FALSE;
	}
	this->Notify();
	this->Invalidate();
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
	isComposition = FALSE;
	this->Invalidate();
	this->Notify();

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
		glyph = this->glyphFactory->FactoryCreator(nChar);
		this->line->Add(glyph);

		this->isComposition = TRUE;
		if (this->line->GetAt(this->line->GetCurrent())==0) {
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


/*
파일명 : NotePad.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : 노트패드 CFrameWnd 선언
수정내용 :OnChar,OnImeChar,OnImeCOMPOSITION 
수정 : factory method pattern 적용
*/
//NotePad.h
#ifndef _NOTEPAD_H
#define _NOTEPAD_H
#include <afxwin.h>
#include <string>
#include "Subject.h"
#pragma warning (disable:4996)
using namespace std;
typedef signed long int Long;
class Glyph;
class Paper;
class Line;
class CharacterMatrix;
class CaretController;
class GlyphFactory;
class KeyAction;
class MouseAction;
class Positioner;
class Range;
class Reverse;
class NotePad :public CFrameWnd, public Subject {
public:
	NotePad();
	BOOL GetIsComposition() const;
	Glyph* GetPaper() const;
	Glyph* GetLine() const;
	Glyph* GetGlyph() const;
	UINT GetNChar() const;
	Glyph* SetPaper(Glyph* paper);
	Glyph* SetLine(Glyph* line);
	BOOL SetIsComposition(BOOL ret);
	BOOL GetIsDragging() const;
	BOOL GetIsRange() const;
	CPoint GetCursorPoint() const;
	
private:
	string name;
	Glyph* paper;
	Glyph* line;
	Glyph* glyph;
	UINT nChar;
	CFont font; //폰트 선언
	CPoint cursorPoint;
	CharacterMatrix* characterMatrix;
	CaretController* caretController;
	GlyphFactory* glyphFactory;
	MouseAction* mouseAction;
	Positioner* positioner;
	Range* range;
	Reverse* reverse;

	BOOL isComposition = FALSE;
	BOOL isDragging = FALSE;
	BOOL isRange = FALSE;

protected:	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();	
	afx_msg void OnChar(UINT nChar,UINT nRepCnt,UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeChar(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImeStartComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnKillFocus(CWnd *NewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()

};
inline BOOL NotePad::GetIsComposition() const {
	return this->isComposition;
}
inline Glyph* NotePad::GetPaper() const {
	return this->paper;
}
inline Glyph* NotePad::GetLine() const {
	return this->line;
}
inline Glyph* NotePad::GetGlyph() const {
	return this->glyph;
}
inline UINT NotePad::GetNChar() const {
	return this->nChar;
}
inline Glyph* NotePad::SetLine(Glyph* line){
	this->line = line;
	return this->line;
}
inline Glyph* NotePad::SetPaper(Glyph* paper) {
	this->paper = paper;
	return this->paper;
}
inline BOOL NotePad::SetIsComposition(BOOL ret) {
	this->isComposition = ret;
	return this->isComposition;
}
inline BOOL NotePad::GetIsDragging() const {
	return this->isDragging;
}
inline CPoint NotePad::GetCursorPoint() const {
	return this->cursorPoint;
}
inline BOOL NotePad::GetIsRange() const {
	return this->isRange;
}
#endif//_NOTEPAD_H

	
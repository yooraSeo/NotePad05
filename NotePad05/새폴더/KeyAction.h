//KeyAction.h
/*
파일명 : KeyAction.h
작성일자 : 2018년 05월 03일
작성자 : 임정훈
기능 : 키보드 기능 키들의 입력을 담당하여 해당 기능을 처리
수정 : -
*/

#ifndef _KEYACTION_H
#define _KEYACTION_H
#include <afxwin.h>
typedef signed long int Long;
class NotePad;
class Positioner;
class KeyAction{
public:
	KeyAction();	
	KeyAction(NotePad* notePad);
	~KeyAction();
	CPoint HomeKey(UINT nChar);
	CPoint EndKey(UINT nChar);
	CPoint LeftKey(UINT nChar);
	CPoint RightKey(UINT nChar);
	CPoint UpKey(UINT nChar);
	CPoint DownKey(UINT nChar);
	CPoint Priorkey(UINT nChar);
	CPoint NextKey(UINT nChar);
	CPoint BackspaceKey(UINT nChar);
private:
	NotePad * notePad;
	Positioner* positioner;
	Long column;
	Long row;
	CPoint point;
};

#endif // !_KEYACTION_H
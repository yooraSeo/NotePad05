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

class NotePad;
class KeyAction{
public:
	KeyAction(NotePad* notePad);	
	~KeyAction();
	virtual void Action() = 0;
protected:
	NotePad * notePad;
};

#endif // !_KEYACTION_H
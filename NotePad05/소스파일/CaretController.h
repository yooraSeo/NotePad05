//CaretController.h
/*
파일명 : CaretController.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : Caret Controll
수정 : -
*/

#ifndef _CARETCONTROLLER_H
#define _CARETCONTROLLER_H
#include "Observer.h"
class NotePad;
class Caret;
class CaretController: public Observer {
public:
	CaretController();
	CaretController(NotePad* notePad);
	CaretController(const CaretController& source);
	~CaretController();
	void Update();
	CaretController& operator=(const CaretController& souce);
private:
	NotePad* notePad;
	Caret* caret;
};
#endif // !_CARETCONTROLLER_H


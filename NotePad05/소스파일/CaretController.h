//CaretController.h
/*
���ϸ� : CaretController.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : Caret Controll
���� : -
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


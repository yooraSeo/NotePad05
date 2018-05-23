//Caret.cpp
/*
���ϸ� : Caret.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : Caret ���� �� �Ҹ�, Move,Show ��,����,������,������
���� : -
*/

#include "Caret.h"
#include "NotePad.h"
Caret::Caret() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->heigh = 0;
	this->notePad = 0;
}

Caret::Caret(NotePad* notePad, Long width, Long heigh) {
	this->x = 0;
	this->y = 0;
	this->width = width;
	this->heigh = heigh;
	this->notePad = notePad;
	this->notePad->CreateSolidCaret(width, heigh);
}

Caret::Caret(const Caret& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->heigh = source.heigh;
	this->notePad = source.notePad;
}

Caret::~Caret() {

	DestroyCaret();
}

Caret& Caret::operator=(const Caret& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->heigh = source.heigh;
	this->notePad = source.notePad;
	return *this;
}

bool Caret::Move(Long x, Long y) {
	
	CPoint point(x, y);
	this->notePad->SetCaretPos(point);	
	return true;
}

bool Caret::Show(bool isShow) {
	//BOOL ret;
	if (isShow == true) {
		this->notePad->ShowCaret();
	}
	return true;
}

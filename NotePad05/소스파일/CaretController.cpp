//CaretController.cpp
/*
���ϸ� : CaretController.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : Caret Controll
���� : -
*/
#include "CaretController.h"
#include "CharacterMatrixSingletonPattern.h"
#include "Positioner.h"
#include "Caret.h"
#include "NotePad.h"
#include "Line.h"
#include "CharacterMatrix.h"

typedef signed long int Long;
CaretController::CaretController() {
	this->notePad =0;
	this->caret = 0;
}

CaretController::CaretController(NotePad* notePad) {
	this->notePad = notePad;
	this->caret = 0;
	this->notePad->Add(this);
}

CaretController::CaretController(const CaretController& source) {
	this->notePad = source.notePad;
	this->caret = source.caret;
}

void CaretController::Update() {
	
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	Positioner positioner;
	
	Long row = notePad->GetPaper()->GetCurrent();
	Long column = notePad->GetLine()->GetCurrent();
	Line* line = (Line*)notePad->GetLine();
	Long x = positioner.GetX(notePad, line, column);
	Long y = positioner.GetY(notePad, row);
	bool ret;
	if (caret != NULL) {
		this->notePad->HideCaret();
		caret = NULL;
	}
	if (notePad->GetIsComposition() == TRUE) {
		caret = new Caret(notePad, characterMatrix->GetWidths(128), characterMatrix->GetHeigh());
		ret = caret->Move(x, y);
	}
	else {
		caret = new Caret(notePad, 2, characterMatrix->GetHeigh());
		ret = caret->Move(x, y);
	}
	caret->Show(ret);
}

CaretController& CaretController::operator=(const CaretController& source) {
	this->notePad = source.notePad;
	this->caret = source.caret;
	return *this;
}
CaretController::~CaretController() {
	if (this->caret != 0) {
		delete this->caret;
		this->caret = 0;
	}
	this->notePad->Delete(this);
}
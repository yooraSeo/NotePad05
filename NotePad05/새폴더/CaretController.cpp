//CaretController.cpp
/*
파일명 : CaretController.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : Caret Controll
수정 : -
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
	Long y = positioner.GetY(notePad, row+1);
	bool ret;
	if (caret != 0) {
		caret = 0;
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
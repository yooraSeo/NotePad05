//Positioner.cpp
/*
파일명 : Positioner.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : Caret Position 값 제어 및 설정. x,y,column,row
수정 : -
*/
#include "Positioner.h"
#include "CharacterMatrix.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include "Glyph.h"
#include "Line.h"
#include "NotePad.h"
#include "CharacterMatrixSingletonPattern.h"

Positioner::Positioner() {
	this->x = 0;
	this->y = 0;
	this->row = 0;
	this->column = 0;
}

Positioner::Positioner(const Positioner& source) {
	this->x = source.x;
	this->y = source.y;
	this->row = source.row;
	this->column = source.column;
}

Positioner::~Positioner() {
}

Positioner& Positioner::operator=(const Positioner& source) {
	this->x = source.x;
	this->y = source.y;
	this->row = source.row;
	this->column = source.column;
	return *this;
}

Long Positioner::GetX(NotePad *notePad, Glyph* line, Long column) {
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	string str;
	Long i = 0;
	
	(this->x) = 0;
	while (i < column) {
		if (dynamic_cast<SingleByteCharacter*>(line->GetAt(i))) {
			str = line->GetAt(i)->MakeString();
			(this->x) += characterMatrix->GetWidths(str[0]);
		}
		else if(dynamic_cast<DoubleByteCharacter*>(line->GetAt(i))){
			(this->x) += characterMatrix->GetWidths(128);
		}
		i++;
	}
	return this->x;
}

Long Positioner::GetY(NotePad *notePad, Long row) {
	CharacterMatrix* charactermatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	this->y = (charactermatrix->GetHeigh())*row;
	return this->y;
}

Long Positioner::GetRow(NotePad* notePad, Long y) {
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	Long height = characterMatrix->GetHeigh();
	this->row = y / height;
	if (this->row >= notePad->GetPaper()->GetLength()) {
		this->row = notePad->GetPaper()->GetLength() - 1;
	}
	return this->row;
}

Long Positioner::GetColumn(NotePad* notePad, Glyph* line, Long x) {
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	Long leng = line->GetLength();
	Long lineX = this->GetX(notePad, line, leng);
	Long temp = 0;
	Long frontSum;
	Long rearSum;
	Long i = 0;
	if (x < lineX) {
		while (i <= leng && temp < x) {
			temp = this->GetX(notePad, line, i);
			i++;
		}
		if (i > 1) {
			frontSum = this->GetX(notePad, line, i - 2);
			rearSum = this->GetX(notePad, line, i - 1);
			if (x - frontSum <= rearSum - x) {
				this->column = i - 2;
			}
			else {
				this->column = i - 1;
			}
		}
		else {
			this->column = i;
		}
	}
	else {
		this->column = leng;
	}
	return this->column;
}
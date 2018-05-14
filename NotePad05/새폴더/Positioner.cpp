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
	this->x = 0;
	
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
	this->y = (charactermatrix->GetHeigh())*(row-1);
	return this->y;
}

Long Positioner::GetRow(NotePad *notePad,Glyph *paper ,Long y) {
	CharacterMatrix* charactermatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	if (y >= 0 && y < this->GetY(notePad, paper->GetLength())) {
		this->row = y / charactermatrix->GetHeigh();
	}
	else if (y <= paper->GetLength()) {
		this->row = paper->GetLength();
	}
	return this->row;
}

Long Positioner::GetColumn(NotePad *notePad, Glyph* line, Long x) {
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	Long lengX = this->GetX(notePad, line, line->GetLength());
	Long leng = line->GetLength();
	Long sumX = this->GetX(notePad, line, 0);
	Long i = 1;
	Long prevX = 0;
	if (x <= this->GetX(notePad, line, 1)) {
		this->column = 0;
	}
	else if (x < lengX) {
		while (i < leng && sumX < x) {
			prevX = sumX;
			sumX = this->GetX(notePad, line, i);
			i++;
		}
		if (x - prevX > sumX - x) {
			this->column = i - 1;
		}
		else {
			this->column = i - 2;
		}
	}
	else if (x >= lengX) {
		this->column = leng;
	}
	return this->column;
}


//	Long i = 0;
//	Long xOne = 0;
//	Long y = this->GetX(notePad, line, line->GetLength());
//	if (x >=0 && x < y) {
//		while (xOne < x && i <= line->GetLength()) {
//			xOne = this->GetX(notePad, line, i);
//			i++;
//		}
//		if(this->)
//		this->column = i - 2;
//		
//	}
//	else {
//		this->column = line->GetLength();
//	}
//	return this->column;
//}
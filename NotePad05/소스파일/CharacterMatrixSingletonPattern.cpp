/*
파일명 : CharacterMatrixSingletonPattern.h
작성일자 : 2018년 04월 24일
작성자 : 허수진
기능 : CharacterMatrix을 SingletonPattern에 적용함
수정 : 	-
*/

//CharacterMatrixSingletonPattern
#include "CharacterMatrixSingletonPattern.h"
#include "NotePad.h"
#include "CharacterMatrix.h"

CharacterMatrix* CharacterMatrixSingletonPattern::_instance = 0;

CharacterMatrix* CharacterMatrixSingletonPattern::Instance(NotePad *notePad) {
	if (_instance == 0) {
		_instance = new CharacterMatrix(notePad);
	}
	return _instance;
}

CharacterMatrixSingletonPattern::CharacterMatrixSingletonPattern(NotePad* notePad) {
	this->notePad = notePad;
}


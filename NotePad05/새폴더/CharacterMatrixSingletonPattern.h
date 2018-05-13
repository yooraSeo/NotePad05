/*
파일명 : CharacterMatrixSingletonPattern.h
작성일자 : 2018년 04월 24일
작성자 : 허수진
기능 : CharacterMatrix을 SingletonPattern에 적용함
수정 : 	-
*/

#ifndef _CHARATERMATRIXSINGITONPATTERN_H
#define _CHARATERMATRIXSINGITONPATTERN_H

class NotePad;
class CharacterMatrix;

class CharacterMatrixSingletonPattern {

public:
	static CharacterMatrix* Instance(NotePad* notePad);
	CharacterMatrixSingletonPattern(NotePad* natePad);

private:
	static CharacterMatrix* _instance;
	NotePad* notePad;
};
#endif // !_CHARATERMATRIXSINGITONPATTERN_H

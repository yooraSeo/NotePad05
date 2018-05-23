/*
파일명 : Character.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : Character(싱글, 더블) 추상 클래스 선언
수정 : -
*/

//Character.h
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "Glyph.h"

class Character:public Glyph{
public:
	Character();
	virtual ~Character()=0;
};
#endif // !_CHARACTER_H

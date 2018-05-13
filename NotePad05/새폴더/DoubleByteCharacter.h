/*
파일명 : DoubleByteCharacter.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : DoubleByteCharacter의 생성자, 매개변수를 갖는 생성자, 복사생성자, 소멸자, 클론(prototype pattern), 문자열 만들기, 연산자 =선언
수정 : -
*/
//DoubleByteCharacter.h
#ifndef _DOUBLEBYTECHARACTER_H
#define _DOUBLEBYTECHARACTER_H
#include "Character.h"
#include <string.h>

using namespace std;

class DoubleByteCharacter:public Character{
public:
	DoubleByteCharacter();
	DoubleByteCharacter(char (*object));
	DoubleByteCharacter(const DoubleByteCharacter& source);
	virtual ~DoubleByteCharacter();
	virtual Glyph* Clone();
	DoubleByteCharacter& operator=(const DoubleByteCharacter& source);
	virtual string MakeString();

private:
	char object[2];
};

#endif // !_DOUBLEBYTECHARACTER_H

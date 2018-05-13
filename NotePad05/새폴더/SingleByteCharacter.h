/*
파일명 : SingleByteCharacter.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : SingleByteCharacter의 생성자, 매개변수를 갖는 생성자, 복사생성자, 소멸자, 클론(prototype pattern), 문자열 만들기, 연산자 =선언
수정 : -
*/
//SingleByteCharacter.h
#ifndef _SINGLEBYTECHARACTER_H
#define _SINGLEBYTECHARACTER_H
#include "Character.h"
#include <string.h>

using namespace std;

class SingleByteCharacter:public Character{
public:
	SingleByteCharacter();
	SingleByteCharacter(char object);
	SingleByteCharacter(const SingleByteCharacter& source);
	virtual ~SingleByteCharacter();
	virtual Glyph* Clone();
	SingleByteCharacter& operator=(const SingleByteCharacter& source);
	virtual string MakeString();
	

private:
	char object;
};

#endif // !_SINGLEBYTECHARACTER_H

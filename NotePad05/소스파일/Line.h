/*
파일명 : Line.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : entity로 한줄을 의미 ->생성자, 복사생성자, 소멸자, 클론, 문자열 만들기, 연산자= 선언
수정 : -
*/
//Line.h
#ifndef _LINE_H
#define _LINE_H
#include "Composite.h"
#include <string.h>

using namespace std;
class Line :public Composite {
public:
	Line(Long capacity=256);
	Line(const Line& source);
	virtual ~Line();
	virtual Glyph* Clone();
	virtual string MakeString();
	Line& operator=(const Line& sorce);
};

#endif // !_LINE_H




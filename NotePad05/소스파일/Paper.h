/*
파일명 : Paper.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : entity로 한 단락을 의미 line을 관리함->생성자, 복사생성자, 소멸자, 클론, 문자열 만들기, 연산자= 선언
수정 : -
*/
//Paper.h
#ifndef _PAPER_H
#define _PAPER_H
#include "Composite.h"
#include <string.h>
using namespace std;
class Paper :public Composite {
public:
	Paper(Long capacity = 256);
	Paper(const Paper& source);
	~Paper();
	virtual Glyph* Clone();
	virtual string MakeString();
	Paper& operator=(const Paper& source);
};

#endif // !_PAPER_H

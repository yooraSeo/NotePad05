/*
파일명 : Glyph.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : notePad의 super 클래스 선언
수정 : -
*/
 
//Glyph.h
#ifndef _GLYPH_H
#define _GLYPH_H
#include <string>

typedef signed long int Long;
using namespace std;

class  Glyph {
public:
	Glyph();
	virtual ~Glyph()=0;
	virtual string MakeString() = 0;
	virtual Glyph* Clone()=0;
	virtual Long Add(Glyph* glyph) { return -1; }
	virtual Glyph* GetAt(Long index) { return 0; }
	virtual Long Remove(Long index) { return -1; }
	virtual Long Prev() { return 0; }
	virtual Long Next() { return 0; }
	virtual Long First() { return 0; }
	virtual Long Last() { return 0; }
	virtual Long GetCapacity() const { return 0; }
	virtual Long GetLength() const { return 0; }
	virtual Long GetCurrent() const { return 0; }
	virtual Long SetCurrent(Long index) const { return 0; }
};
#endif //_GLYPH_H
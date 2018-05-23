/*
파일명 : GlyphFactory.h
작성일자 : 2018년 04월 26일
작성자 : 허수진
기능 : glyph 생성자 관리
수정 : -
*/

//GlyphFactory.h
#ifndef  _GIYPHFACTORY_H
#define __GIYPHFACTORY_H
#include <string>
#include "NotePad.h"


typedef signed long int Long;
using namespace std;
class Glyph;
class GlyphFactory {
public:
	GlyphFactory();
	~GlyphFactory();
	virtual Glyph* FactoryCreator(char(*characters));
};
#endif // ! _GIYPHFACTORY_H

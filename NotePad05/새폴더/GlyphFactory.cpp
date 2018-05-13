/*
파일명 : GlyphFactory.cpp
작성일자 : 2018년 04월 26일
작성자 : 허수진
기능 : glyph 생성자 관리
수정 : -
*/
//GlyphFactory.cpp
#include "GlyphFactory.h"
#include "Paper.h"
#include "Line.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
GlyphFactory::GlyphFactory() {
}

GlyphFactory::~GlyphFactory() {
}

Glyph* GlyphFactory::FactoryCreator(char(*characters)) {
	Glyph* glyph=NULL;

	if (characters == 0) {
		glyph = new Paper;
	}
	else if (characters[0] == '\r' || characters[0] == '\n') {
		glyph = new Line;
	}
	else if (31 < characters[0] && characters[0] < 128) {
		glyph = new SingleByteCharacter(characters[0]);
	}
	else if (characters[0] & 0x80) {//한글을 읽을 때 한글에 대한 유니코드 수가 필요한데 더 생각해봐야 함.
		glyph = new DoubleByteCharacter(characters);
	}
	return glyph;
}

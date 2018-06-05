/*
���ϸ� : GlyphFactory.cpp
�ۼ����� : 2018�� 04�� 26��
�ۼ��� : �����
��� : glyph ������ ����
���� : -
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
		glyph = new Paper();
	}
	else if (characters[0] == '\r' || characters[0] == '\n') {
		glyph = new Line();
	}
	else if (characters[0] > 31 && characters[0] < 128) {
		glyph = new SingleByteCharacter(characters[0]);
	}
	else if (characters[0] & 0x80) {//�ѱ��� ���� �� �ѱۿ� ���� �����ڵ� ���� �ʿ��ѵ� �� �����غ��� ��.
		glyph = new DoubleByteCharacter(characters);
	}
	return glyph;
}

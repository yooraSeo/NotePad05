/*
���ϸ� : GlyphFactory.h
�ۼ����� : 2018�� 04�� 26��
�ۼ��� : �����
��� : glyph ������ ����
���� : -
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

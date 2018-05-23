/*
���ϸ� : DoubleByteCharacter.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : DoubleByteCharacter�� ������, �Ű������� ���� ������, ���������, �Ҹ���, Ŭ��(prototype pattern), ���ڿ� �����, ������ =����
���� : -
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

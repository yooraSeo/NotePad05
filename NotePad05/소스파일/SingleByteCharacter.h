/*
���ϸ� : SingleByteCharacter.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : SingleByteCharacter�� ������, �Ű������� ���� ������, ���������, �Ҹ���, Ŭ��(prototype pattern), ���ڿ� �����, ������ =����
���� : -
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

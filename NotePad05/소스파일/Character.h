/*
���ϸ� : Character.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : Character(�̱�, ����) �߻� Ŭ���� ����
���� : -
*/

//Character.h
#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "Glyph.h"

class Character:public Glyph{
public:
	Character();
	virtual ~Character()=0;
};
#endif // !_CHARACTER_H

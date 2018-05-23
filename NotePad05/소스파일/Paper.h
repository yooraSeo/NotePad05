/*
���ϸ� : Paper.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : entity�� �� �ܶ��� �ǹ� line�� ������->������, ���������, �Ҹ���, Ŭ��, ���ڿ� �����, ������= ����
���� : -
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

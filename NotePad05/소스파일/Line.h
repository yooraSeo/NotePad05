/*
���ϸ� : Line.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : entity�� ������ �ǹ� ->������, ���������, �Ҹ���, Ŭ��, ���ڿ� �����, ������= ����
���� : -
*/
//Line.h
#ifndef _LINE_H
#define _LINE_H
#include "Composite.h"
#include <string.h>

using namespace std;
class Line :public Composite {
public:
	Line(Long capacity=256);
	Line(const Line& source);
	virtual ~Line();
	virtual Glyph* Clone();
	virtual string MakeString();
	Line& operator=(const Line& sorce);
};

#endif // !_LINE_H




/*
���ϸ� : Composite.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : paper�� line�� �����ϴ� �߻� Ŭ������ ������, ���������, �Ҹ���, add, getAt ������ =���� (�Ӽ�: �Ҵ緮, ��뷮, ������ġ)
���� : 	-
*/
//Composite.h
#ifndef _COMPOSITE_H
#define _COMPOSITE_H
#include "Glyph.h"
#include "Array.h"

typedef signed long int Long;

class Composite : public Glyph {
public:
	Composite(Long capacity = 256);
	Composite(const Composite & source);
	virtual ~Composite();
	virtual Long Add(Glyph* glyph);
	virtual Glyph* GetAt (Long index);
	virtual Long Remove(Long index);
	virtual Long Next();
	virtual Long Prev();
	virtual Long First();
	virtual Long Last();
	virtual Long SetCurrent(Long index);

	Composite & operator = (const Composite & source);
	
	virtual Long GetCapacity() const;
	virtual Long GetLength() const;
	virtual Long GetCurrent() const;
	
protected:
	Array <Glyph*> glyphes;
	Long capacity;
	Long length;
	Long current;
};
inline Long Composite::GetCapacity() const {
	return this->capacity;
}
inline Long Composite::GetLength() const {
	return this->length;
}
inline Long Composite::GetCurrent() const {
	return this->current;
}
#endif // !_COMPOSITE_H


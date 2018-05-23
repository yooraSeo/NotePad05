//Positioner.h
/*
���ϸ� : Positioner.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : Caret Position �� ���� �� ����. x,y,column,row
	GetX(line,column),GetX(),GetY(row),GetY(),GetRow(),GetColumn()
���� : -
*/

#ifndef _POSITIONER_H
#define _POSIIONER_H
typedef signed long int Long;
class NotePad;
class Glyph;

class Positioner{
public:
	Positioner();
	Positioner(const Positioner& source);
	~Positioner();
	Long GetX(NotePad *notePad, Glyph* line, Long column);
	Long GetY(NotePad *notePad, Long row);
	Long GetRow(NotePad* notePad, Long x);
	Long GetColumn(NotePad* notePad, Glyph* line, Long y);
	Positioner& operator=(const Positioner& source);
	Long GetX() const;
	Long GetY() const;
	Long GetRow() const;
	Long GetColumn() const;
private:
	Long x;
	Long y;
	Long row;
	Long column;
};
inline Long Positioner::GetX() const {
	return this->x;
}
inline Long Positioner::GetY() const {
	return this->y;
}
inline Long Positioner::GetRow() const {
	return this->row;
}
inline Long Positioner::GetColumn() const {
	return this->column;
}
#endif // !_POSITIONER_H

//Positioner.h
/*
파일명 : Positioner.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : Caret Position 값 제어 및 설정. x,y,column,row
	GetX(line,column),GetX(),GetY(row),GetY(),GetRow(),GetColumn()
수정 : -
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
	Long GetRow(NotePad* notePad,Glyph* paper, Long y);
	Long GetColumn(NotePad *notePad, Glyph *line, Long x);
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

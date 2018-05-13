//Caret.h
/*
파일명 : Caret.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : Caret 생성 및 소멸, Move,Show 폭,높이,가로축,세로축
수정 : -
*/

#ifndef _CARET_H
#define _CARET_H
typedef signed long int Long;
class NotePad;
class Caret{
public:
	Caret();
	Caret(NotePad* notePad, Long width, Long heigh);
	Caret(const Caret& source);
	~Caret();
	bool Move(Long x, Long y);
	bool Show(bool isShow);
	Caret& operator=(const Caret& source);
	Long GetX() const;
	Long GetY() const;
	Long GetWidth() const;
	Long GetHeigh() const;
private:
	Long x;
	Long y;
	Long width;
	Long heigh;	
	NotePad* notePad;
};

inline Long Caret::GetWidth() const {
	return this->width;
}
inline Long Caret::GetHeigh() const {
	return this->heigh;
}
inline Long Caret::GetX() const {
	return this->x;
}
inline Long Caret::GetY() const {
	return this->y;
}
#endif // !_CARET_H

//CharacterMatrix.h
/*
파일명 : CharacterMatrix.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : 아스키코드의 배열을 가지고 문자의 높이,폭을 구한다.
수정 : singleton 분리
*/
#ifndef _CHARACTERMATRIX_H
#define _CHARACTERMATRIX_H


typedef signed long int Long;
class Caret;
class NotePad;
class CharacterMatrix {
public:	
	Long GetHangleWidth() const;
	Long GetWidths(Long code) const;
	Long GetHeigh() const;
	//static CharacterMatrix * GetInstance(NotePad *notepad);
	CharacterMatrix();
	CharacterMatrix(NotePad* notePad);
	CharacterMatrix(const CharacterMatrix& source);
	~CharacterMatrix();
	CharacterMatrix& operator=(const CharacterMatrix& source);
private:
	//static CharacterMatrix* _instance;
	Long widths[129];
	Long heigh;
	NotePad* notePad;
	Caret* caret;
};

inline Long CharacterMatrix::GetHangleWidth() const {
	return this->widths[128];
}
inline Long CharacterMatrix::GetWidths(Long code) const {
	return this->widths[code];
}
inline Long CharacterMatrix::GetHeigh() const {
	return this->heigh;
}

#endif // !_CHARACTERMATRIX_H


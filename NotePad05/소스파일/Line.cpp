/*
파일명 : Line.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : entity로 한줄을 의미 ->생성자, 복사생성자, 소멸자, 클론, 문자열 만들기, 연산자= 정의
수정 : -
*/
//Line.cpp
#include "Line.h"

Line::Line(Long capacity):Composite(capacity){
}

Line::Line(const Line& source) : Composite(source) {
}

Line::~Line() {
}

Glyph* Line::Clone() {
	return new Line(*this);
}

string Line::MakeString() {
	string text = "";
	Long i = 0;
	Glyph* glyph;
	
	while (i < this->GetLength()) {
		if (this->glyphes.GetAt(i) != NULL) {
			glyph = this->glyphes.GetAt(i);
			text += glyph->MakeString();
		}
		i++;
	}
	return text;
}

Line& Line::operator=(const Line& source) {
	Composite::operator=(source);
	return *this;
}


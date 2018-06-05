/*
파일명 : DoubleByteCharacter.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : DoubleByteCharacter의 생성자, 매개변수를 갖는 생성자, 복사생성자, 소멸자, 클론(prototype pattern), 문자열 만들기, 연산자 =정의
수정 : -
*/
//DoubleByteCharacter.cpp
#include "DoubleByteCharacter.h"
#include "Visitor.h"

DoubleByteCharacter::DoubleByteCharacter()
{
	this->object[0] = ' ';
	this->object[1] = ' ';
	
}


DoubleByteCharacter::DoubleByteCharacter(char (*object)) {
	this->object[0] = object[0];
	this->object[1] = object[1];

}
DoubleByteCharacter::DoubleByteCharacter(const DoubleByteCharacter& source) {
	this->object[0] = source.object[0];
	this->object[1] = source.object[1];

}
DoubleByteCharacter::~DoubleByteCharacter(){
}
Glyph* DoubleByteCharacter::Clone() {

	return new DoubleByteCharacter(*this);
}

DoubleByteCharacter& DoubleByteCharacter::operator=(const DoubleByteCharacter& source) {
	this->object[0] = source.object[0];
	this->object[1] = source.object[1];
	
	return *this;
}
string DoubleByteCharacter::MakeString() {
	string buffer;
	buffer += this->object[0];
	buffer += this->object[1];
	return buffer;
}

string DoubleByteCharacter::GetTab() {
	string buffer;
	buffer += this->object[0];
	buffer += this->object[1];
	return buffer;
}

void DoubleByteCharacter::Accept(Visitor& visitor) {
	visitor.Visit(this);
}

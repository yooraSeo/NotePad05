/*
파일명 : SingleByteCharacter.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : SingleByteCharacter의 생성자, 매개변수를 갖는 생성자, 복사생성자, 소멸자, 클론(prototype pattern), 문자열 만들기, 연산자 =정의
수정 : -
*/
//SingleByteCharacter.cpp
#include "SingleByteCharacter.h"
#include "Visitor.h"

SingleByteCharacter::SingleByteCharacter(){
	this->object = ' ';
}
SingleByteCharacter::SingleByteCharacter(char object) {
	this->object = object;
}
SingleByteCharacter::SingleByteCharacter(const SingleByteCharacter& source) {
	this->object = source.object;
}
SingleByteCharacter::~SingleByteCharacter(){
}
SingleByteCharacter& SingleByteCharacter::operator=(const SingleByteCharacter& source) {
	this->object = source.object;
	return *this;
}
string SingleByteCharacter::MakeString() {
	string buffer;
	string temp;
	temp = this->object;
	if (temp == "\t") {
		buffer = " ";
	}
	else {
		buffer = this->object;
	}
	return buffer;
}

string SingleByteCharacter::GetTab() {
	string buffer;
	buffer = this->object;
	return buffer;
}
Glyph* SingleByteCharacter::Clone() {
	
	return new SingleByteCharacter(*this);
}

void SingleByteCharacter::Accept(Visitor& visitor) {
	visitor.Visit(this);
}
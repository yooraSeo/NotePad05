/*
���ϸ� : DoubleByteCharacter.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : DoubleByteCharacter�� ������, �Ű������� ���� ������, ���������, �Ҹ���, Ŭ��(prototype pattern), ���ڿ� �����, ������ =����
���� : -
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

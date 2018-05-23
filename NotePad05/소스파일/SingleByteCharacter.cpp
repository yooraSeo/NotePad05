/*
���ϸ� : SingleByteCharacter.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : SingleByteCharacter�� ������, �Ű������� ���� ������, ���������, �Ҹ���, Ŭ��(prototype pattern), ���ڿ� �����, ������ =����
���� : -
*/
//SingleByteCharacter.cpp
#include "SingleByteCharacter.h"

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
	buffer = this->object;
	return buffer;
}
Glyph* SingleByteCharacter::Clone() {
	
	return new SingleByteCharacter(*this);
}
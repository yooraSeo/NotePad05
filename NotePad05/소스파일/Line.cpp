/*
���ϸ� : Line.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : entity�� ������ �ǹ� ->������, ���������, �Ҹ���, Ŭ��, ���ڿ� �����, ������= ����
���� : -
*/
//Line.cpp
#include "Line.h"
#include "Visitor.h"

Line::Line(Long capacity):Composite(capacity){
}

Line::Line(const Line& source) : Composite(source) {
}

Line::~Line() {
}

Glyph* Line::Clone() {
	return new Line(*this);
}

void Line::Accept(Visitor& visitor) {
	visitor.Visit(this);
}

string Line::MakeString() {
	string text = "";
	string temp = "";
	Long i = 0;
	Glyph* glyph;

	while (i < this->GetLength()) {
		if (this->glyphes.GetAt(i) != NULL) {
			glyph = this->glyphes.GetAt(i);
			temp = glyph->MakeString();
			if (temp == "\t") {
				text += " ";
			}
			else {
				text += glyph->MakeString();
			}
		}
		i++;
	}
	return text;
}

string Line::GetTab() {
	string text = "";
	Long i = 0;
	Glyph* glyph;

	while (i < this->GetLength()) {
		if (this->glyphes.GetAt(i) != NULL) {
			glyph = this->glyphes.GetAt(i);
			text += glyph->GetTab();
		}
		i++;
	}
	return text;
}

Line& Line::operator=(const Line& source) {
	Composite::operator=(source);
	return *this;
}


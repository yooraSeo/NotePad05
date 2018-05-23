/*
파일명 : Paper.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : entity로 한 단락을 의미 line을 관리함->생성자, 복사생성자, 소멸자, 클론, 문자열 만들기, 연산자= 정의
수정 : -
*/
//Paper.cpp
#include "Paper.h"

Paper::Paper(Long capacity):Composite(capacity){
}

Paper::Paper(const Paper& source):Composite(source){
}

Paper::~Paper() {
}

Glyph* Paper::Clone() {
	return new Paper(*this);
}

string Paper::MakeString() {
	string text = "";
	Long i = 0;
	Glyph* line;
	while (i < this->GetLength()) {
		line = this->GetAt(i);
		text += line->MakeString();
		i++;
	}
	return text;
}

Paper& Paper::operator=(const Paper& source) {
	Composite::operator=(source);
	return *this;
}


#include <iostream>
#include "Line.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
using namespace std;

int main(int argc, char argv[]) {
	Long index;
	//Long position;
	Glyph* paper = new Paper(1);
	index = paper->Add(new Line);
	Glyph* line = paper->GetAt(index);
	//position = line->Add(new SingleByteCharacter('1'));

	//cout << line->GetAt(position)->MakeString().c_str() << endl;


	//position = line->Add(new SingleByteCharacter('2'));
	////position = line->Remove(position);
	//cout << line->GetAt(position)->MakeString().c_str()<< endl;

	//position = line->Add(new SingleByteCharacter('3'));
	//cout << line->GetAt(position)->MakeString().c_str() << endl;
	//
	//char han[3] = "한";
	//position = line->Add(new DoubleByteCharacter(han));
	//cout << line->GetAt(position)->MakeString().c_str() << endl;
	//
	//char kuk[3] = "국";
	//position = line->Add(new DoubleByteCharacter(kuk));
	//cout << line->GetAt(position)->MakeString().c_str() << endl;

	//index = paper->Add(new Line);
	//Glyph* lineOne = paper->GetAt(index);
	//position = lineOne->Add(new SingleByteCharacter('A'));
	//position = lineOne->Add(new SingleByteCharacter('a'));
	//cout << lineOne->MakeString().c_str() << endl;
	//


	//index = paper->Add(new Line);
	//Glyph* lineTwo = paper->GetAt(index);
	//position = lineTwo->Add(new SingleByteCharacter('B'));
	//position = lineTwo->Add(new SingleByteCharacter('b'));
	//cout << lineTwo->MakeString().c_str() << endl;

	//cout << paper->MakeString() << endl;
	return 0;
}


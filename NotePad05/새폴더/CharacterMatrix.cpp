//CharacterMatrix.cpp
/*
파일명 : CharacterMatrix.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : 아스키코드의 배열을 가지고 문자의 높이,폭을 구한다.
수정 : singleton 분리
*/

#include "CharacterMatrix.h"
#include "NotePad.h"
#include <string>
using namespace std;

CharacterMatrix::CharacterMatrix() {
	this->heigh = 0;
	this->notePad = 0;
	this->caret = 0;
}

using namespace std;
CharacterMatrix::CharacterMatrix(NotePad* notePad) {
	this->notePad = notePad;
	char str;
	Long i = 0;
	TEXTMETRIC textMetric;
	CDC *pDc=notePad->GetDC();
	GetTextMetrics(pDc->GetSafeHdc(), &textMetric);
	/*CFont *pCurFont = notePad->GetFont();
	pDc->SelectObject(pCurFont);*/
	while (i <= 127) {
		
		str =(TCHAR)i;
		this->widths[i] = (pDc->GetTextExtent(str).cx);
		i++;
	}
	this->widths[128] = (pDc->GetTextExtent("한").cx);
	this->heigh = textMetric.tmHeight;//폰트 높이의 평균으로 바꿔야함
	//this->heigh = (pDc.GetTextExtent("한").cy);
}

CharacterMatrix::CharacterMatrix(const CharacterMatrix& source) {
	Long i = 0;
	while (i <= 128) {
		this->widths[i] = source.widths[i];
		i++;
	}
	this->heigh = source.heigh;
	this->notePad = source.notePad;
}
CharacterMatrix::~CharacterMatrix() {
}

CharacterMatrix& CharacterMatrix::operator=(const CharacterMatrix& source) {
	Long i = 0;
	while (i <= 128) {
		this->widths[i] = source.widths[i];
		i++;
	}
	this->heigh = source.heigh;
	this->notePad = source.notePad;
	
	return *this;
}

//CharacterMatrix* CharacterMatrix::_instance = 0;
//CharacterMatrix* CharacterMatrix::GetInstance(NotePad *notepad) {
//	if (_instance == 0) {
//		_instance = new CharacterMatrix(notepad);
//	}
//	return _instance;
//}
//

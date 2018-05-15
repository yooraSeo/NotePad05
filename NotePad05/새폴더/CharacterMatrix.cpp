//CharacterMatrix.cpp
/*
���ϸ� : CharacterMatrix.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : �ƽ�Ű�ڵ��� �迭�� ������ ������ ����,���� ���Ѵ�.
���� : singleton �и�
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
	this->widths[128] = (pDc->GetTextExtent("��").cx);
	this->heigh = textMetric.tmHeight;//��Ʈ ������ ������� �ٲ����
	//this->heigh = (pDc.GetTextExtent("��").cy);
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

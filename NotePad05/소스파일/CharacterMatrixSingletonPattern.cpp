/*
���ϸ� : CharacterMatrixSingletonPattern.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : �����
��� : CharacterMatrix�� SingletonPattern�� ������
���� : 	-
*/

//CharacterMatrixSingletonPattern
#include "CharacterMatrixSingletonPattern.h"
#include "NotePad.h"
#include "CharacterMatrix.h"

CharacterMatrix* CharacterMatrixSingletonPattern::_instance = 0;

CharacterMatrix* CharacterMatrixSingletonPattern::Instance(NotePad *notePad) {
	if (_instance == 0) {
		_instance = new CharacterMatrix(notePad);
	}
	return _instance;
}

CharacterMatrixSingletonPattern::CharacterMatrixSingletonPattern(NotePad* notePad) {
	this->notePad = notePad;
}


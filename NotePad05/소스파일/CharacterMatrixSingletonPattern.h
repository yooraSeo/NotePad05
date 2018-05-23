/*
���ϸ� : CharacterMatrixSingletonPattern.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : �����
��� : CharacterMatrix�� SingletonPattern�� ������
���� : 	-
*/

#ifndef _CHARATERMATRIXSINGITONPATTERN_H
#define _CHARATERMATRIXSINGITONPATTERN_H

class NotePad;
class CharacterMatrix;

class CharacterMatrixSingletonPattern {

public:
	static CharacterMatrix* Instance(NotePad* notePad);
	CharacterMatrixSingletonPattern(NotePad* natePad);

private:
	static CharacterMatrix* _instance;
	NotePad* notePad;
};
#endif // !_CHARATERMATRIXSINGITONPATTERN_H

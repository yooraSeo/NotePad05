//CharacterMatrix.h
/*
���ϸ� : CharacterMatrix.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : �ƽ�Ű�ڵ��� �迭�� ������ ������ ����,���� ���Ѵ�.
���� : singleton �и�
*/
#ifndef _CHARACTERMATRIX_H
#define _CHARACTERMATRIX_H


typedef signed long int Long;
class Caret;
class NotePad;
class CharacterMatrix {
public:	
	Long GetHangleWidth() const;
	Long GetWidths(Long code) const;
	Long GetHeigh() const;
	//static CharacterMatrix * GetInstance(NotePad *notepad);
	CharacterMatrix();
	CharacterMatrix(NotePad* notePad);
	CharacterMatrix(const CharacterMatrix& source);
	~CharacterMatrix();
	CharacterMatrix& operator=(const CharacterMatrix& source);
private:
	//static CharacterMatrix* _instance;
	Long widths[129];
	Long heigh;
	NotePad* notePad;
	Caret* caret;
};

inline Long CharacterMatrix::GetHangleWidth() const {
	return this->widths[128];
}
inline Long CharacterMatrix::GetWidths(Long code) const {
	return this->widths[code];
}
inline Long CharacterMatrix::GetHeigh() const {
	return this->heigh;
}

#endif // !_CHARACTERMATRIX_H


//Caret.h
/*
���ϸ� : Caret.h
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : Caret ���� �� �Ҹ�, Move,Show ��,����,������,������
���� : -
*/

#ifndef _CARET_H
#define _CARET_H
typedef signed long int Long;
class NotePad;
class Caret{
public:
	Caret();
	Caret(NotePad* notePad, Long width, Long heigh);
	Caret(const Caret& source);
	~Caret();
	bool Move(Long x, Long y);
	bool Show(bool isShow);
	Caret& operator=(const Caret& source);
	Long GetX() const;
	Long GetY() const;
	Long GetWidth() const;
	Long GetHeigh() const;
private:
	Long x;
	Long y;
	Long width;
	Long heigh;	
	NotePad* notePad;
};

inline Long Caret::GetWidth() const {
	return this->width;
}
inline Long Caret::GetHeigh() const {
	return this->heigh;
}
inline Long Caret::GetX() const {
	return this->x;
}
inline Long Caret::GetY() const {
	return this->y;
}
#endif // !_CARET_H

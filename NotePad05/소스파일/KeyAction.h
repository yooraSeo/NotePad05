//KeyAction.h
/*
���ϸ� : KeyAction.h
�ۼ����� : 2018�� 05�� 03��
�ۼ��� : ������
��� : Ű���� ��� Ű���� �Է��� ����Ͽ� �ش� ����� ó��
���� : -
*/

#ifndef _KEYACTION_H
#define _KEYACTION_H

class NotePad;
class KeyAction{
public:
	KeyAction(NotePad* notePad);	
	~KeyAction();
	virtual void Action() = 0;
protected:
	NotePad * notePad;
};

#endif // !_KEYACTION_H
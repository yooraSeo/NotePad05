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
#include <afxwin.h>
typedef signed long int Long;
class NotePad;
class Positioner;
class KeyAction{
public:
	KeyAction();	
	KeyAction(NotePad* notePad);
	~KeyAction();
	CPoint HomeKey(UINT nChar);
	CPoint EndKey(UINT nChar);
	CPoint LeftKey(UINT nChar);
	CPoint RightKey(UINT nChar);
	CPoint UpKey(UINT nChar);
	CPoint DownKey(UINT nChar);
	CPoint Priorkey(UINT nChar);
	CPoint NextKey(UINT nChar);
	CPoint BackSpaceKey(UINT nChar);
	CPoint DeleteKey(UINT nChar);
private:
	NotePad * notePad;
	Positioner* positioner;
	Long column;
	Long row;
	CPoint point;
};

#endif // !_KEYACTION_H
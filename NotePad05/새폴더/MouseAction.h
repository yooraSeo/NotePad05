//MouseAction.h
#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include <afxwin.h>

typedef signed long int Long;
class NotePad;
class Positioner;
class Glyph;

class MouseAction {
public:
	MouseAction();
	MouseAction(NotePad* notePad);
	~MouseAction();
	CPoint Clicked(CPoint point);
	CPoint DoubleClicked();
	CPoint Drag(CPoint point);//범위를 지정하다가 완료되어야!
private:
	NotePad * notePad;
	Positioner* positioner;
	CPoint point;
	Glyph* paper;
	Glyph* line;
	Long x;
	Long y;
};

#endif // !_MOUSEACTION_H

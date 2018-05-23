

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
	CPoint Clicked(UINT nFlags, CPoint point);
	CPoint DoubleClicked();
	//CPoint Drag(UINT nFlags, CPoint point);
	~MouseAction();
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

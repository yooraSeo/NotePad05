

#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include <afxwin.h>
typedef signed long int Long;
class NotePad;
class Positioner;
class Glyph;
class Range;
class MouseAction {
public:
	MouseAction();
	MouseAction(NotePad* notePad);
	CPoint Move(UINT nFlags, CPoint point);
	void DoubleClicked(NotePad* notePad, Range* range);
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

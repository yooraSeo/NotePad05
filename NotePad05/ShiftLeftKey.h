//ShiftLeftKey.h
#ifndef _SHIFTLEFTKEY_H
#define _SHIFTLEFTKEY_H
#include "KeyAction.h"

class NotePad;
class ShiftLeftKey :public KeyAction {
public:
	ShiftLeftKey(NotePad* notePad);
	~ShiftLeftKey();
	virtual void Action();
};
#endif // !_SHIFTLEFTKEY_H


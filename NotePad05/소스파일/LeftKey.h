//LeftKey.h

#ifndef _LEFTKEY_H
#define _LEFTKEY_H
#include "KeyAction.h"

class NotePad;
class LeftKey :public KeyAction {
public:
	LeftKey(NotePad* notePad);
	~LeftKey();
	virtual void Action();
};

#endif // !_LEFTKEY_H

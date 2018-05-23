//BackSpaceKey.h

#ifndef _BACKSPACEKEY_H
#define _BACKSPACEKEY_H
#include "KeyAction.h"

class NotePad;
class BackSpaceKey :public KeyAction {
public:
	BackSpaceKey(NotePad* notePad);
	~BackSpaceKey();
	virtual void Action();
};
#endif // !_BACKSPACEKEY_H

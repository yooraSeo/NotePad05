//RightKey.h

#ifndef _RIGHTKEY_H
#define _RIGHTKEY_H
#include "KeyAction.h"

class NotePad;
class RightKey :public KeyAction {
public:
	RightKey(NotePad* notePad);
	~RightKey();
	virtual void Action();
};
#endif // !_RIGHTKEY_H


//DownKey.h

#ifndef _DOWNKEY_H
#define _DOWNKEY_H
#include "KeyAction.h"
class NotePad;
class DownKey :public KeyAction {
public:
	DownKey(NotePad* notePad);
	~DownKey();
	virtual void Action();
};
#endif // !_DOWNKEY_H


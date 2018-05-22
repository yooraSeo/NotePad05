//HomeKey.h

#ifndef _HOMEKEY_H
#define _HOMEKEY_H
#include "KeyAction.h"

class NotePad;
class HomeKey :public KeyAction{
public:
	HomeKey(NotePad* notePad);
	virtual void Action();
	~HomeKey();
};
#endif // !_HOMEKEY_H


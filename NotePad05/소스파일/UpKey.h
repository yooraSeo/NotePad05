//UpKey.h

#ifndef _UPKEY_H
#define _UPKEY_H
#include "KeyAction.h"

class NotePad;
class UpKey :public KeyAction {
public:
	UpKey(NotePad* notePad);
	~UpKey();
	virtual void Action();
};
#endif // !_UPKEY_H


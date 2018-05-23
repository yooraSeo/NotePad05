//EscKey.h

#ifndef _ESCKEY_H
#define _ESCKEY_H
#include "KeyAction.h"

class NotePad;
class EscKey :public KeyAction {
public:
	EscKey(NotePad* notePad);
	~EscKey();
	virtual void Action();
};

#endif // !_ESCKEY_H


//PriorKey.h
#ifndef _PRIORKEY_H
#define _PRIORKEY_H
#include "KeyAction.h"

class NotePad;
class PriorKey :public KeyAction {
public:
	PriorKey(NotePad* notePad);
	~PriorKey();
	virtual void Action();
};
#endif // !_PRIORKEY_H


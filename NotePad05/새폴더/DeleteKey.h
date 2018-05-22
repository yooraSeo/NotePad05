//DeleteKey.h

#ifndef _DELETEKEY_H
#define _DELETEKEY_H
#include "KeyAction.h"

class NotePad;
class DeleteKey :public KeyAction {
public:
	DeleteKey(NotePad* notePad);
	~DeleteKey();
	virtual void Action();
};
#endif // !_DELETEKEY_H

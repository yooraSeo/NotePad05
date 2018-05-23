//NextKey.h
#ifndef _NEXTKEY_H
#define _NEXTKEY_H
#include "KeyAction.h"

class NotePad;
class NextKey :public KeyAction {
public:
	NextKey(NotePad* notePad);
	~NextKey();
	virtual void Action();
};
#endif // !_NEXTKEY_H


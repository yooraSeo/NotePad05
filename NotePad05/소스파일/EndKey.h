//EndKey.h
#ifndef _ENDKEY_H
#define _ENDKEY_H
#include "KeyAction.h"
class NotePad;
class EndKey :public KeyAction{
public:
	EndKey(NotePad* notePad);
	~EndKey();
	virtual void Action();
};
#endif // !_ENDKEY_H

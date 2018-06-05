//IntervalRightKey.h

#ifndef _INTERVALRIGHTKEY_H
#define _INTERVALRIGHTKEY_H
#include "IntervalKeyAction.h"

class IntervalRightKey :public IntervalKeyAction {
public:
	IntervalRightKey(NotePad* notePad);
	~IntervalRightKey();
	virtual void IntervalAction();
private:
	NotePad* notePad;
};
#endif // !_INTERVALRIGHTKEY_H


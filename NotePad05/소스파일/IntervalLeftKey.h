//IntervalLeftKey.h

#ifndef _INTERVALLEFTKEY_H
#define _INTERVALLEFTKEY_H
#include "IntervalKeyAction.h"

class NotePad;
class IntervalLeftKey :public IntervalKeyAction {
public:
	IntervalLeftKey(NotePad* notePad);
	~IntervalLeftKey();
	virtual void IntervalAction();
private:
	NotePad * notePad;
};
#endif // !_INTERVALLEFTKEY_H


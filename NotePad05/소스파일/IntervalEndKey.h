//IntervalEndKey.h

#ifndef _INTERVALENDKEY_H
#define _INTERVALENDKEY_H
#include "IntervalKeyAction.h"

class NotePad;
class IntervalEndKey :public IntervalKeyAction {
public:
	IntervalEndKey(NotePad* notePad);
	~IntervalEndKey();
	virtual void IntervalAction();
private:
	NotePad * notePad;
};
#endif // !_INTERVALENDKEY_H


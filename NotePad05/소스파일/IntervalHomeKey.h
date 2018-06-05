//IntervalHomeKey.h

#ifndef _INTERVALHOMEKEY_H
#define _INTERVALHOMEKEY_H
#include "IntervalKeyAction.h"

class NotePad;
class IntervalHomeKey :public IntervalKeyAction{
public:
	IntervalHomeKey(NotePad* notePad);
	~IntervalHomeKey();
	virtual void IntervalAction();
private:
	NotePad * notePad;
};
#endif // ! _INTERVALHOMEKEY_H


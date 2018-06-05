//IntervalActionCreator.h

#ifndef _INTERVALACTIONCREATOR_H
#define _INTERVALACTIONCREATOR_H

typedef unsigned int UINT;
class IntervalKeyAction;
class NotePad;
class IntervalActionCreator {
public:
	IntervalActionCreator();
	~IntervalActionCreator();
	IntervalKeyAction* Create(NotePad* notePad,UINT nChar);
private:
	IntervalKeyAction * intervalKeyAction;
};
#endif // !_INTERVALACTIONCREATOR_H


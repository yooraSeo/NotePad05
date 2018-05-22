//ActionCreator.h

#ifndef _ACTIONCREATOR_H
#define _ACTIONCREATOR_H

typedef unsigned int UINT;
class NotePad;
class KeyAction;
class ActionCreator {
public:
	ActionCreator();
	~ActionCreator();
	KeyAction* Create(NotePad* notePad, UINT nChar);
private:
	KeyAction * keyAction;
};
#endif // !_ACTIONCREATOR_H


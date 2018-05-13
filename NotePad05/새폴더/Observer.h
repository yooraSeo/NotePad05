//Observer.h
#ifndef _OBSERVER_H
#define _OBSERVER_H
class Subject;
class Observer {
public:
	virtual ~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};

#endif // !_OBSERVER_H

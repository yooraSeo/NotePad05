//Subject.h
#ifndef _SUBJECT_H
#define _SUBJECT_H
#include "Array.h"

class Observer;
class Subject{
public:
	virtual ~Subject();
	virtual void Add(Observer* observer);
	virtual void Delete(Observer* observer);
	virtual void Notify();
protected:
	Subject(Long capacity = 256);
private:
	Array<Observer*> observers;
	Long capacity;
	Long length;
};

#endif // !_SUBJECT_H

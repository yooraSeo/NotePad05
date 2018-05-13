//Subject.cpp
#include "Subject.h"
#include "Observer.h"

Subject::~Subject() {
}

Subject::Subject(Long capacity):observers(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

void Subject::Add(Observer* observer) {
	this->observers.Store(this->length, observer);
	(this->capacity)++;
	(this->length)++;
}

void Subject::Delete(Observer* observer) {
	Long i = 0;
	while (i < this->length && observer != this->observers.GetAt(i)) {
		i++;
	}
	if (observer == this->observers.GetAt(i)) {
		this->observers.Delete(i);
	}
	(this->length)--;
	(this->capacity)--;
}

void Subject::Notify() {
	Long i = 0;
	while (i < this->length) {
		this->observers[i]->Update();
		i++;
	}
}

//IntervalKeyAction.cpp
#include "IntervalKeyAction.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "Positioner.h"

IntervalKeyAction::IntervalKeyAction(NotePad* notePad) {
	this->symbols[0] = 32;
	this->symbols[1] = 33; 
	this->symbols[2] = 36;
	this->symbols[3] = 37;
	this->symbols[4] = 40;
	this->symbols[5] = 43;
	this->symbols[6] = 45;
	this->symbols[7] = 60;
	this->symbols[8] = 63;
	this->symbols[9] = 91;
	this->symbols[10] = 92;
	this->symbols[11] = 123;
	this->symbols[12] = 124;
	this->notePad = notePad;
}
IntervalKeyAction::~IntervalKeyAction() {

}
	
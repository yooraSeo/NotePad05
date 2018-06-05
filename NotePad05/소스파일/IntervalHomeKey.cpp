//IntervalHomeKey.cpp

#include "IntervalHomeKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"

IntervalHomeKey::IntervalHomeKey(NotePad* notePad):IntervalKeyAction(notePad) {
	this->notePad = notePad;
}

IntervalHomeKey::~IntervalHomeKey() {

}

void IntervalHomeKey::IntervalAction() {
	Paper* paper = (Paper*)notePad->GetPaper();
	Long row = paper->First();
	Line* line = (Line*)paper->GetAt(row);
	line->First();
	notePad->SetPaper(paper);
	notePad->SetLine(line);
}
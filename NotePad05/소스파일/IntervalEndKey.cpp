//IntervalEndKey.cpp

#include "IntervalEndKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"

IntervalEndKey::IntervalEndKey(NotePad* notePad):IntervalKeyAction(notePad) {
	this->notePad = notePad;
}

IntervalEndKey::~IntervalEndKey() {

}

void IntervalEndKey::IntervalAction() {
	Paper* paper = (Paper*)notePad->GetPaper();
	paper->Last();
	Long row = paper->Prev();
	paper->SetCurrent(row);
	Line* line = (Line*)paper->GetAt(row);
	line->Last();
	notePad->SetPaper(paper);
	notePad->SetLine(line);
}
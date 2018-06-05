//PriorKey.cpp

#include "PriorKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"

PriorKey::PriorKey(NotePad* notePad) :KeyAction(notePad) {

}

PriorKey::~PriorKey() {

}

void PriorKey::Action() {
	
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->GetCurrent();
	if (row != 0) {
		column = line->GetCurrent();
		row = paper->First();
		line = (Line*)paper->GetAt(row);
		if (column < line->GetLength()) {
			line->SetCurrent(column);
		}
		else {
			column = line->Last();
		}
		notePad->SetPaper(paper);
		notePad->SetLine(line);
	}
}
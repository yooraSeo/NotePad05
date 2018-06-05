//LeftKey.cpp

#include "LeftKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "Positioner.h"

LeftKey::LeftKey(NotePad* notePad):KeyAction(notePad) {

}

LeftKey::~LeftKey() {

}

void LeftKey::Action() {
	CPoint point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->GetCurrent();
	Positioner positioner;
	if (column > 0 || point.x != positioner.GetX(notePad, line, column)) {
		if (point.x == positioner.GetX(notePad, line, column)) {
			column = line->Prev();
		}
	}
	else if (row > 0) {
		row = paper->Prev();
		line = (Line*)paper->GetAt(row);
		column = line->Last();
		notePad->SetPaper(paper);
	}
	notePad->SetLine(line);
}
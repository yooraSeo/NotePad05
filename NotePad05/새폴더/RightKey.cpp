//RightKey.cpp

#include "RightKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"


RightKey::RightKey(NotePad* notePad):KeyAction(notePad) {
}

RightKey::~RightKey() {

}

void RightKey::Action() {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->GetCurrent();
	if (column < line->GetLength()) {
		column = line->Next();
	}
	else if (row < paper->GetLength() - 1) {
		row = paper->Next();
		line = (Line*)paper->GetAt(row);
		column = line->First();
		notePad->SetPaper(paper);
	}
	this->notePad->SetLine(line);
	this->notePad->Notify();
}
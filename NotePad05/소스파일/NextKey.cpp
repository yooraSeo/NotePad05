//NextKey.cpp

#include "NextKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"

NextKey::NextKey(NotePad* notePad) :KeyAction(notePad) {

}

NextKey::~NextKey() {

}

void NextKey::Action() {
	//CPoint point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->GetCurrent();

	if (row < paper->GetLength() - 1) {
		column = line->GetCurrent();
		paper->Last();
		row = paper->Prev();
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
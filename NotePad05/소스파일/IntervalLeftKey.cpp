//IntervalLeftKey.cpp

#include "IntervalLeftKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"

IntervalLeftKey::IntervalLeftKey(NotePad* notePad):IntervalKeyAction(notePad) {
	this->notePad = notePad;
}

IntervalLeftKey::~IntervalLeftKey() {

}

void IntervalLeftKey::IntervalAction() {
	Paper* paper = (Paper*)notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)paper->GetAt(row);
	Long column = line->GetCurrent();
	BOOL getSymbol = FALSE;
	if (column > 0) {
		Long current = line->Prev();
		string str;
		Long code;
		Long i;
		while (current > 0 && getSymbol == FALSE) {
			str = line->GetAt(current)->MakeString();
			code = str[0];
			i = 0;
			while (i < 13 && this->GetSymbols()[i] != code) {
				i++;
			}
			if (this->GetSymbols()[0] == code || this->GetSymbols()[i] == code) {
				getSymbol = TRUE;
			}
			current = line->Prev();
		}
		if (getSymbol == TRUE) {
			if (code == this->GetSymbols()[0]) {
				line->Next();
				while (code == this->GetSymbols()[0] && current > 0) {
					current = line->Prev();
					str = line->GetAt(current)->MakeString();
					code = str[0];
				}
			}
			if (current != 0) {
				line->Next();
			}
		}
		else {
			line->First();
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
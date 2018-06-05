//IntervalRightKey.cpp

#include "IntervalRightKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"

IntervalRightKey::IntervalRightKey(NotePad* notePad) :IntervalKeyAction(notePad) {
	this->notePad = notePad;
}

IntervalRightKey::~IntervalRightKey() {

}

void IntervalRightKey::IntervalAction() {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)paper->GetAt(row);
	Long column = line->GetCurrent();
	BOOL getSymbol = FALSE;
	if (column < line->GetLength()) {
		Long current = column;
		string str;
		Long code;
		Long i;
		while (current < line->GetLength() && getSymbol == FALSE) {
			str = line->GetAt(current)->MakeString();
			code = str[0];
			i = 0;
			while (i < 13 && this->GetSymbols()[i] != code) {
				i++;
			}
			if (this->GetSymbols()[i] == code) {
				getSymbol = TRUE;
			}
			current = line->Next();
		}
		if (getSymbol == TRUE) {
			if (code == this->GetSymbols()[0]) {
				line->Prev();
				while (code == this->GetSymbols()[0] && current < line->GetLength()) {
					current = line->Next(); 
					if (current < line->GetLength()) {
						str = line->GetAt(current)->MakeString();
						code = str[0];
					}
				}
			
			}
		}
		else {
			line->Last();
		}
	}
	else if (row < paper->GetLength() - 1) {
		row = paper->Next();
		line = (Line*)paper->GetAt(row);
		column = line->First();
		notePad->SetPaper(paper);
	}
	notePad->SetLine(line);
}
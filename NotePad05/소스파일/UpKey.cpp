//UpKey.cpp

#include "UpKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "Positioner.h"

UpKey::UpKey(NotePad* notePad):KeyAction(notePad) {

}

UpKey::~UpKey() {

}

void UpKey::Action() {

CPoint point = this->notePad->GetCaretPos();
Paper* paper = (Paper*)this->notePad->GetPaper();
Long row = paper->GetCurrent();
Line* line = (Line*)this->notePad->GetLine();
Long column = line->GetCurrent();
Positioner positioner;
Long i;
Long x;
Long leng;
Long temp;
Long sum;
if (row > 0) {
	column = line->GetCurrent();
	row = paper->Prev();
	line = (Line*)paper->GetAt(row);
	x = point.x;
	leng = line->GetLength();
	temp = 0;
	sum = x - temp;
	if (column <= leng) {
		if (positioner.GetX(notePad, line, column) != x) {
			i = 1;
			while (i <= leng && positioner.GetX(notePad, line, i) < x) {
				temp = positioner.GetX(notePad, line, i);
				if (sum > x - temp) {
					sum = x - temp;
				}
				i++;
			}
			if (i > leng) {
				i = leng;
			}
			temp = positioner.GetX(notePad, line, i) - x;
			if (i <= leng && sum < temp) {
				column = i - 1;
			}
			else {
				column = i;
			}
			line->SetCurrent(column);
		}
		else {
			line->SetCurrent(column);
		}
	}
	else {
		if (positioner.GetX(notePad, line, leng) > x) {
			Long i = 1;
			while (i <= leng && positioner.GetX(notePad, line, i) < x) {
				temp = positioner.GetX(notePad, line, i);
				if (sum > x - temp) {
					sum = x - temp;
				}
				i++;
			}
			if (i > leng) {
				i = leng;
			}
			temp = positioner.GetX(notePad, line, i) - x;
			if (i <= leng && sum < temp) {
				column = i - 1;
			}
			else {
				column = i;
			}
			column = i;
			line->SetCurrent(column);
		}
		else {
			column = line->Last();
		}
	}
}
notePad->SetPaper(paper);
notePad->SetLine(line);
notePad->Notify();
}
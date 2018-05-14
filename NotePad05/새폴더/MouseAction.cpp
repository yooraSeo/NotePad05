//MouseAction.cpp

#include "MouseAction.h"
#include "NotePad.h"
#include "Positioner.h"
#include "Glyph.h"
#include "Line.h"
#include "Paper.h"

MouseAction::MouseAction() {
	this->notePad = 0;
	this->positioner = 0;
	this->point = 0;
	this->paper = 0;
	this->line = 0;
	this->x = 0;
	this->y = 0;
}

MouseAction::MouseAction(NotePad* notePad) {
	this->notePad = notePad;
	this->positioner = new Positioner();
	this->point = this->notePad->GetCaretPos();
	this->paper = this->notePad->GetPaper();
	this->line = this->notePad->GetLine();
	this->x = this->point.x;
	this->y = this->point.y;	
}

MouseAction::~MouseAction() {

}

CPoint MouseAction::Clicked(CPoint point) {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	//if (paper->GetCurrent() == paper->GetLength()) {
	//	paper->Prev();
	//}
	Long row;
	if (point.y < this->positioner->GetY(this->notePad, paper->GetLength())) {
		row = this->positioner->GetRow(notePad, (Glyph*)paper, point.y);
	}
	else {
		row = paper->Last()-1;
	}
	paper->SetCurrent(row);

	Line* line = (Line*)this->notePad->GetPaper()->GetAt(row);
	Long column;
	if (point.x < this->positioner->GetX(this->notePad, line, line->GetLength())) {
		column = this->positioner->GetColumn(notePad, (Glyph*)line, point.x);
	}
	else {
		column = line->Last();
	}
	line->SetCurrent(column);

	//this->notePad->GetLine()->SetCurrent(column);
	this->notePad->SetLine(line);
	this->notePad->SetPaper(paper);
	this->point.x = column;
	this->point.y = row;
	this->notePad->Notify();
	return this->point;
}

CPoint MouseAction::DoubleClicked() {
	return this->point;
}

CPoint MouseAction::Drag(CPoint point) {
	return this->point;
}




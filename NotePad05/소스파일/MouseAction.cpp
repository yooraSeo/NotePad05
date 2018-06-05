//MouseAction.cpp

#include "MouseAction.h"
#include "NotePad.h"
#include "Positioner.h"
#include "Glyph.h"
#include "Paper.h"
#include "Line.h"
#include "CharacterMatrixSingletonPattern.h"
#include "CharacterMatrix.h"
#include <afxwin.h>
#include "Range.h"
#include "IntervalRightKey.h"
#include "IntervalLeftKey.h"


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

CPoint MouseAction::Move(UINT nFlags, CPoint point) {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = this->positioner->GetRow(this->notePad, point.y);
	if (row >= 0) {
		paper->SetCurrent(row);
		this->notePad->SetPaper(paper);
		Line* line = (Line*)this->notePad->GetPaper()->GetAt(row);
		Long column = this->positioner->GetColumn(this->notePad, line, point.x);
		line->SetCurrent(column);
		this->notePad->SetLine(line);
	}
	
	//this->notePad->Notify();
	return this->point;
}

void MouseAction::DoubleClicked(NotePad* notePad, Range* range){

	Line* line = (Line*)notePad->GetLine();
	Long column = line->GetCurrent();

	if (column != 0 && column < line->GetLength()) {
		IntervalLeftKey* intervalLeftKey = new IntervalLeftKey(notePad);
		intervalLeftKey->IntervalAction();
		if (notePad->GetLine()->GetCurrent() > 0) {
			notePad->GetLine()->Next();
		}
		range->Reset(notePad);
		line->SetCurrent(column);
		notePad->SetLine(line);
		IntervalRightKey * intervalRightKey = new IntervalRightKey(notePad);
		intervalRightKey->IntervalAction();
		range->Sum(notePad);
	}
	else if (column == 0) {
		range->Reset(notePad);
		IntervalRightKey * intervalRightKey = new IntervalRightKey(notePad);
		intervalRightKey->IntervalAction();
		range->Sum(notePad);
	}
	else if (column >= notePad->GetLine()->GetLength()) {
		range->Reset(notePad);
		IntervalLeftKey* intervalLeftKey = new IntervalLeftKey(notePad);
		intervalLeftKey->IntervalAction();
		range->Sum(notePad);
	}

}



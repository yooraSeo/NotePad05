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

CPoint MouseAction::Clicked(UINT nFlags, CPoint point) {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Long row = this->positioner->GetRow(this->notePad, point.y);
	paper->SetCurrent(row);
	this->notePad->SetPaper(paper);
	Line* line = (Line*)this->notePad->GetPaper()->GetAt(row);
	Long column = this->positioner->GetColumn(this->notePad, line, point.x);
	line->SetCurrent(column);
	this->notePad->SetLine(line);
	this->notePad->Notify();
	//notePad->Invalidate();
	return this->point;
}

CPoint MouseAction::DoubleClicked() {

	return this->point;
}

//CPoint MouseAction::Drag(UINT nFlags, CPoint point) {
//
//	return this->point;
//}


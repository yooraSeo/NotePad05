//ShiftLeftKey.cpp

#include "ShiftLeftKey.h"
#include "NotePad.h"
#include <afxwin.h>
#include "Positioner.h"
#include "Paper.h"
#include "Line.h"
#include "LeftKey.h"

ShiftLeftKey::ShiftLeftKey(NotePad* notePad) :KeyAction(notePad) {

}

ShiftLeftKey::~ShiftLeftKey() {

}

void ShiftLeftKey::Action() {
	Positioner positioner;
	CPoint point = this->notePad->GetCaretPos();
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
		Long startRow = positioner.GetRow(this->notePad, point.y);
		Long endRow = startRow;
		Paper* paper = (Paper*)this->notePad->GetPaper();
		Line* line = (Line*)this->notePad->GetPaper()->GetAt(startRow);
		Long startColumn = positioner.GetColumn(this->notePad, line, point.x);
		Long endColumn = startColumn;
		LeftKey* leftKey;
		leftKey->Action();
	}

	//if (this->notePad->GetPaper()->GetLength() > 0 && line->GetLength() > 0) {
	//	if (endColumn > 0) {
	//		endColumn--;
	//	}
	//	else {
	//		this->notePad->GetPaper()->Prev();
	//		line = (Line*)paper->GetAt(paper->GetCurrent());
	//		endColumn = line->Last();
	//	}

	//	dc.SetTextColor(RGB(255, 255, 255));
	//	dc.SetBkColor(RGB(54, 138, 255));
	//}
}
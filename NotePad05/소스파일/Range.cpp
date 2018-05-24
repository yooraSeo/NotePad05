//Range.cpp

#include "Range.h"
#include "NotePad.h"
#include "Positioner.h"
#include "Paper.h"
#include "Line.h"
#include "CharacterMatrix.h"
#include "CharacterMatrixSingletonPattern.h"

Range::Range() {
	this->startRow = 0;
	this->endRow = 0;
	this->startColumn = 0;
	this->endColumn = 0;
	this->notePad = 0;
	this->point = 0;
}

Range::Range(NotePad* notePad, Long row, Long column) {
	this->startRow = row;
	this->endRow = row;
	this->startColumn = column;
	this->endColumn = column;
	this->notePad = notePad;
	this->point = 0;
}

Range::Range(NotePad* notePad, CPoint point) {
	this->startRow = 0;
	this->endRow = 0;
	this->startColumn = 0;
	this->endColumn = 0;
	this->notePad = notePad;
	this->point = point;
}

Range::Range(const Range& source) {
	this->startRow = source.startRow;
	this->endRow = source.endRow;
	this->startColumn = source.startColumn;
	this->endColumn = source.endColumn;
	this->notePad = source.notePad;
	this->point = source.point;
}

Range::~Range() {
}

Range& Range::operator=(const Range& source) {
	this->startRow = source.startRow;
	this->endRow = source.endRow;
	this->startColumn = source.startColumn;
	this->endColumn = source.endColumn;
	return *this;
}

//void Range::MouseDraw(NotePad* notePad, CPoint* point){
//	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
//
//	Paper* paper = (Paper*)notePad->GetPaper();
//	Line* line = (Line*)notePad->GetLine();
//
//	this->startRow = paper->GetCurrent();
//	this->endRow = this->positioner->GetRow(notePad, point->y);
//	this->startColumn = line->GetCurrent()-1;
//	this->endColumn = this->positioner->GetColumn(notePad, line, point->x);
//
//	CRect rect;
//	
//	rect.left = this->positioner->GetX(notePad, paper->GetAt(this->startRow), this->startColumn+1);
//	rect.top = this->positioner->GetY(notePad, this->startRow);
//	rect.right = rect.left;
//	rect.bottom = rect.top + characterMatrix->GetHeigh();
//
//	//rect->SetRect(left, top, right, bottom);
//
//	if (startRow == endRow) {  //같은 줄일 때
//		Long i = 1;
//		Long width = 0;
//		Long temp;
//		if (this->startColumn < this->endColumn) {  //오른쪽으로 가는 방향일 때
//			temp = this->endColumn - this->startColumn;
//			while (i < temp) {
//				if (dynamic_cast<SingleByteCharacter*>(line->GetAt(this->startColumn + i))) {
//					string str = line->GetAt(this->startColumn + i)->MakeString();
//						width += characterMatrix->GetWidths(str[0]);
//				}
//				else if (dynamic_cast<DoubleByteCharacter*>(line->GetAt(this->startColumn + i))) {
//					width += characterMatrix->GetHangleWidth();
//				}
//				i++;
//			}
//			rect.right += width;
//		}
//		//else if (this->endColumn < this->startColumn) {  //왼쪽으로 가는 방향일 때
//		//	temp = this->startColumn - this->endColumn;
//		//	while (i < temp) {
//		//		if (dynamic_cast<SingleByteCharacter*>(line->GetAt(this->startColumn + i))) {
//		//			string str = line->GetAt(this->startColumn + i)->MakeString();
//		//			width += characterMatrix->GetWidths(str[0]);
//		//		}
//		//		else if (dynamic_cast<DoubleByteCharacter*>(line->GetAt(this->startColumn + i))) {
//		//			width += characterMatrix->GetHangleWidth();
//		//		}
//		//		i++;
//		//	}
//		//	rect.left += width;
//		//}
//	}
//	CClientDC dc(notePad);
//	CPen pen;
//	pen.CreatePen(PS_INSIDEFRAME, 0, RGB(54, 138, 255));
//	CPen* oldPen = dc.SelectObject(&pen);
//	CBrush brush;
//	brush.CreateSolidBrush(RGB(54, 138, 255));
//	CBrush* oldBrush = dc.SelectObject(&brush);
//	dc.Rectangle(rect);
//	//dc.SetTextColor(RGB(255, 255, 255));
//	//dc.SetBkMode(TRANSPARENT);
//	//dc.DrawText(CString("아놔아아아아아앙"), CRect(rect->top, rect->left, rect->bottom, rect->right), DT_CENTER);
//}

void Range::Calculate() {
	this->endRow = this->notePad->GetPaper()->GetCurrent();
	Line* line = (Line*)this->notePad->GetPaper()->GetAt(this->endRow);
	this->endColumn = line->GetCurrent();
	Positioner positioner;

	if (this->startRow == this->endRow) {
		this->point.x = positioner.GetX(this->notePad, line, this->startColumn);
		this->point.y = positioner.GetY(this->notePad, this->startRow);
	}
	else if (this->startRow < this->endRow) {

	}
	else if (this->startRow > this->endRow) {

	}
	this->notePad->Notify();
}
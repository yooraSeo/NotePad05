//ReverseVisitor.cpp

#include "ReverseVisitor.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "Range.h"

ReverseVisitor::ReverseVisitor(CDC* dc,NotePad* notePad) {
	this->dc = dc;
	this->notePad = notePad;
}

ReverseVisitor::~ReverseVisitor() {

}

void ReverseVisitor::Visit(Paper* paper) {
	Range range;
	Long i = range.GetStartColumn();
	Long startRow = range.GetStartRow();
	Long endRow = range.GetEndRow();

	while (startRow <= range.GetEndRow()) {
		Glyph* line = paper->GetAt(startRow);
		string text;
		this->dc->SetTextColor(RGB(255, 255, 255));
		this->dc->SetBkColor(RGB(90, 174, 255));
		while (i < range.GetEndColumn()) {
			text += line->GetAt(i)->MakeString();
			i++;
		}
		this->dc->TextOut(range.GetPoint().x, range.GetPoint().y, CString(text.c_str()));
		startRow++;
	}
}

void ReverseVisitor::Visit(Line* line) {

}

void ReverseVisitor::Visit(DoubleByteCharacter* doubleByteCharacter) {

}

void ReverseVisitor::Visit(SingleByteCharacter* singleByteCharacter) {

}
//PaintVisitor.cpp

#include "PaintVisitor.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "CharacterMatrix.h"
#include "CharacterMatrixSingletonPattern.h"
#include <afxwin.h>

PaintVisitor::PaintVisitor(CDC* dc,NotePad* notePad) {
	this->dc = dc;
	this->notePad = notePad;
}

PaintVisitor::~PaintVisitor() {

}

void PaintVisitor::Visit(Paper* paper) {
	Long i = 0;
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(this->notePad);

	while (i < paper->GetLength()) {
		Glyph* line = paper->GetAt(i);
		string text = line->MakeString();
		Long heigh = characterMatrix->GetHeigh();
		//this->dc->SetBkMode(TRANSPARENT);
		this->dc->TextOut(0, (i * heigh), CString(text.c_str()));
		i++;
	}
}

void PaintVisitor::Visit(Line* line) {

}

void PaintVisitor::Visit(DoubleByteCharacter* doubleByteCharacter) {
	
}

void PaintVisitor::Visit(SingleByteCharacter* singleByteCharacter) {
	
}

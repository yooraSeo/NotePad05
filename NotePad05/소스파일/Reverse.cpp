//Reverse.cpp

#include "Reverse.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "Positioner.h"
#include "CharacterMatrix.h"
#include "CharacterMatrixSingletonPattern.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"
#include "Range.h"

Reverse::Reverse(CDC* dc, NotePad* notePad) {
	this->dc = dc;
	this->notePad = notePad;
	this->str = "";
}

void Reverse::ReverseDrow(Range* range){
	
	if (this->notePad->GetIsRange()) {
		CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(this->notePad);
		Paper* paper = (Paper*)notePad->GetPaper();
		Glyph* line = notePad->GetLine();
		Long heigh = characterMatrix->GetHeigh();
		Long i = range->GetStartRow();
		Long j;
		Long width;
		Positioner* positioner = new Positioner();
		Long x;
		this->str = "";

		this->dc->SetTextColor(RGB(255, 255, 255));
		this->dc->SetBkColor(RGB(54, 138, 255));
		this->dc->SetBkMode(TRANSPARENT);
		this->dc->SetBkMode(OPAQUE);

		if (range->GetStartRow() == range->GetEndRow()) {
			if (range->GetStartColumn() < range->GetEndColumn()) {
				i = range->GetStartColumn();
				while (i < range->GetEndColumn()) {
					this->str += line->GetAt(i)->MakeString();
					i++;
				}
				x = positioner->GetX(notePad, line, range->GetStartColumn());
			}
			else if (range->GetStartColumn() > range->GetEndColumn()) {
				i = range->GetEndColumn();
				while (i < range->GetStartColumn()) {
					this->str += line->GetAt(i)->MakeString();
					i++;
				}
				x = positioner->GetX(notePad, line, range->GetEndColumn());
			}
			if (this->str != "") {
				this->dc->TextOut(x, (range->GetStartRow()*heigh), CString(this->str.c_str()));
				this->str = "";
			}
		}
		else if (range->GetStartRow() < range->GetEndRow()) {
			i = range->GetStartRow();
			while (i <= range->GetEndRow()) {
				line = paper->GetAt(i);
				if (i == range->GetStartRow()) {
					j = range->GetStartColumn();
					while (j < line->GetLength()) {
						this->str += line->GetAt(j)->MakeString();
						j++;
					}
					x = positioner->GetX(notePad, line, range->GetStartColumn());
				}
				else if (i == range->GetEndRow()) {
					j = 0;
					while (j < range->GetEndColumn()) {
						this->str += line->GetAt(j)->MakeString();
						j++;
					}
					x = 0;
				}
				else {
					j = 0;
					while (j < line->GetLength()) {
						this->str += line->GetAt(j)->MakeString();
						j++;
					}
					x = 0;
				}
				this->dc->TextOut(x, (i*heigh), CString(this->str.c_str()));
				i++;
				this->str = "";
			}
		}
		else if (range->GetStartRow() > range->GetEndRow()) {
			i = range->GetEndRow();
			while (i <= range->GetStartRow()) {
				line = paper->GetAt(i);
				if (i == range->GetStartRow()) {
					j = 0;
					while (j <range->GetStartColumn()) {
						this->str += line->GetAt(j)->MakeString();
						j++;
					}
					x = 0;
				}
				else if (i == range->GetEndRow()) {
					j = range->GetEndColumn();
					while (j < line->GetLength()) {
						this->str += line->GetAt(j)->MakeString();
						j++;
					}
					x = positioner->GetX(notePad,line,range->GetEndColumn());
				}
				else {
					j = 0;
					while (j < line->GetLength()) {
						this->str += line->GetAt(j)->MakeString();
						j++;
					}
					x = 0;
				}
				
				this->dc->TextOut(x, (i*heigh), CString(this->str.c_str()));
				i++;
				this->str = "";
			}
		}
	}
	this->dc->SetTextColor(RGB(0, 0, 0));
	this->dc->SetBkColor(RGB(255, 255, 255));
}
Reverse::~Reverse() {

}
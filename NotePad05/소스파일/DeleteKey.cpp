//DeleteKey.cpp

#include "DeleteKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"

DeleteKey::DeleteKey(NotePad* notePad) :KeyAction(notePad) {

}

DeleteKey::~DeleteKey() {

}

void DeleteKey::Action() {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->GetCurrent();
	Long row = paper->GetCurrent();

	if (column < line->GetLength()) {
		line->Remove(column);
		line->Next();
	}
	else if (row < paper->GetLength() - 1) {
		Long i = 0;
		Glyph* glyph;
		string  str;
		line = (Line*)paper->GetAt(row + 1);
		str = line->MakeString();
		line = (Line*)paper->GetAt(row);
		Long getCurrent = line->Last();
		char cha[2];
		while (i < 256 && str[i] != '\n' && str[i] != '\0') {
			if (str[i] & 0x80) {
				cha[0] = str[i];
				i++;
				cha[1] = str[i];
				glyph = new DoubleByteCharacter(cha);
			}
			else {
				cha[0] = str[i];
				glyph = new SingleByteCharacter(cha[0]);
			}
			line->Add(glyph);
			i++;
		}
		column = line->SetCurrent(getCurrent);
		paper->Remove(row + 1);
		paper->Next();
	}
	this->notePad->SetLine(line);
	this->notePad->Notify();
}
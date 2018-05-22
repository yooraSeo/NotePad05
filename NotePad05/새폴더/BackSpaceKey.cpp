//BackSpaceKey.cpp

#include "BackSpaceKey.h"
#include "NotePad.h"
#include "Paper.h"
#include "Line.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"

BackSpaceKey::BackSpaceKey(NotePad* notePad):KeyAction(notePad){

}

BackSpaceKey::~BackSpaceKey() {

}

void BackSpaceKey::Action() {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->GetCurrent();
	Long row = paper->GetCurrent();
	Long lineLeng = line->GetLength();

	if (column > 0 && column <= lineLeng) {
		line->Remove(column - 1);
	}
	else if (column <= 0 && row > 0) {
		if (line->GetLength() > 0) {
			Long i = 0;
			Glyph* glyph;
			string  str;
			str = line->MakeString();
			line = (Line*)paper->GetAt(row - 1);
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
			paper->Remove(row);
			(row)--;
		}
		else {
			paper->Remove(row);
			row--;
			line = (Line*)paper->GetAt(row);
			column = line->Last();
			line->SetCurrent(column);
		}
		this->notePad->SetPaper(paper);
	}
	this->notePad->SetLine(line);
	this->notePad->Notify();

}
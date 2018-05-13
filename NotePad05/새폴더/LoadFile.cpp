//LoadFile.cpp
#include "LoadFile.h"
#include "NotePad.h"
#include "Glyph.h"
#include "Paper.h"
#include "Line.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"
//#include "GlyphFactory.h"
#include <string.h>
using namespace std;
LoadFile::LoadFile(NotePad* notePad, string name) {
	this->notePad = notePad;
	this->name = name;
	Glyph* paper = this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	Glyph* glyph;
	CString fName;
	fName.Format("%s.txt", this->name.c_str());
	//GlyphFactory* make;
	FILE *file;
	file = fopen((LPCTSTR)fName, "rt");
	if (file != NULL) {
		Long i;
		char str[256];
		char cha[2];
		while (fgets(str, 255, file) != NULL) {
			paper->Add(new Line);
			line = (Line*)paper->GetAt(paper->GetCurrent());
			i = 0;
			while (i < 256 && str[i] != '\n') {
				//if (str[i] > 127) {
				if (str[i] & 0x80){
					cha[0] = str[i];
					i++;
					cha[1] = str[i];
					//glyph = make->FactoryCreator(cha);
					glyph = new DoubleByteCharacter(cha);
					//line->Add(glyph);
				}
				else {
					cha[0] = str[i];
					//glyph = make->FactoryCreator(cha);
					glyph = new SingleByteCharacter(cha[0]);
					//line->Add(glyph);
				}
				line->Add(glyph);
				i++;
			}
		}
		notePad->SetLine(line);
		fclose(file);
	}else {
		paper->Add(new Line);
		line = (Line*)paper->GetAt(paper->GetCurrent());
	}
}

LoadFile::~LoadFile() {
	if (this->notePad != 0) {
		this->notePad = 0;
	}
}


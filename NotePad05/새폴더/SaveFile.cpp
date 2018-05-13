//SaveFile.cpp
#include "SaveFile.h"
#include "Glyph.h"
#include <stdio.h>
SaveFile::SaveFile(string name, Glyph* paper) {
	this->name = name;
	this->paper = paper;
	string str;
	Long i = 0;
	FILE *file;
	file = fopen("새메모장.txt", "wt");
	if (file != NULL) {
		while (i < this->paper->GetLength()) {
			str = this->paper->GetAt(i)->MakeString();
			fprintf(file, "%s\n", str.c_str());
			i++;
		}
	}
	fclose(file);
}

SaveFile::~SaveFile() {
	if (this->paper != 0) {
		this->paper = 0;
	}
}


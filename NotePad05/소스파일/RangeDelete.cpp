//RangeDelete.cpp
#include "RangeDelete.h"
#include "NotePad.h"
#include "Range.h"
#include "Paper.h"
#include "Line.h"
#include "Glyph.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"

RangeDelete::RangeDelete(NotePad* notePad, Range* range) {
	Paper* paper = (Paper*)notePad->GetPaper();
	Long row = paper->GetCurrent();
	Line* line = (Line*)paper->GetAt(row);
	Long column = line->GetCurrent();
	Long startRow = range->GetStartRow();
	Long startColumn = range->GetStartColumn();
	Long count;
	Long i = 0;
	Long length;
	Long paperCurrent;
	Long lineCurrent;
	string str;
	Glyph* glyph;
	if (startRow != row) {
		if (startRow < row) {
			line = (Line*)paper->GetAt(startRow);
			i = startColumn;
			lineCurrent = startColumn;
			length = line->GetLength();
			while (i < length) {
				line->Remove(lineCurrent);
				i++;
			}
			i = 0;
			line = (Line*)paper->GetAt(row);
			lineCurrent = 0;
			while (i < column) {
				line->Remove(lineCurrent);
				i++;
			}
			str = line->MakeString();
			line = (Line*)paper->GetAt(startRow);
			line->Last();
			char cha[2];
			i = 0;
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
			count = row - startRow;
			paperCurrent = startRow + 1;
			i = 0;
			while (i < count) {
				paper->Remove(paperCurrent);
				i++;
			}
			paper->SetCurrent(startRow);
			line->SetCurrent(startColumn);
		}
		else if (startRow > row) {


			line = (Line*)paper->GetAt(row);
			i = column;
			lineCurrent = column;
			length = line->GetLength();
			while (i < length) {
				line->Remove(lineCurrent);
				i++;
			}
			i = 0;
			line = (Line*)paper->GetAt(startRow);
			lineCurrent = 0;
			while (i < startColumn) {
				line->Remove(lineCurrent);
				i++;
			}
			str = line->MakeString();
			line = (Line*)paper->GetAt(row);
			line->Last();
			char cha[2];
			i = 0;
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
			count = startRow - row;
			paperCurrent = row + 1;
			i = 0;
			while (i < count) {
				paper->Remove(paperCurrent);
				i++;
			}
			paper->SetCurrent(row);
			line->SetCurrent(column);
		}
		notePad->SetPaper(paper);
	}
	else {
		if (startColumn <= column) {
			count = column - startColumn;
			lineCurrent = startColumn;
		}
		else {
			count = startColumn - column;
			lineCurrent = column;
		}
		line->SetCurrent(lineCurrent);
		while (i < count) {
			line->Remove(lineCurrent);
			i++;
		}
		line->SetCurrent(lineCurrent);
	}
	notePad->SetLine(line);
}

RangeDelete::~RangeDelete() {

}
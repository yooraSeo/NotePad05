//Range.cpp

#include "Range.h"
#include "NotePad.h"
#include "Positioner.h"
#include "Paper.h"
#include "Line.h"
#include "CharacterMatrix.h"
#include "CharacterMatrixSingletonPattern.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"

Range::Range(NotePad* notePad) {
	this->startRow = notePad->GetPaper()->GetCurrent();
	this->endRow = this->startRow;
	this->startColumn = notePad->GetLine()->GetCurrent();
	this->endColumn = this->startColumn;
}

Range::Range(const Range& source) {
	this->startRow = source.startRow;
	this->endRow = source.endRow;
	this->startColumn = source.startColumn;
	this->endColumn = source.endColumn;
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

void Range::Sum(NotePad* notePad) {
	this->endRow = notePad->GetPaper()->GetCurrent();
	this->endColumn = notePad->GetLine()->GetCurrent();
}

void Range::Reset(NotePad* notePad) {
	this->startRow = notePad->GetPaper()->GetCurrent();
	this->startColumn = notePad->GetLine()->GetCurrent();
}
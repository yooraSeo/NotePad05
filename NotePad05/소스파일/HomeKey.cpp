//HomeKey.cpp

#include "HomeKey.h"
#include "Line.h"
#include "NotePad.h"

HomeKey::HomeKey(NotePad* notePad):KeyAction(notePad){

}

HomeKey::~HomeKey() {

}

void HomeKey::Action() {
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->First();
	notePad->SetLine(line);
}
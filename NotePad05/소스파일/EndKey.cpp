//EndKey.cpp

#include "EndKey.h"
#include "Line.h"
#include "NotePad.h"

EndKey::EndKey(NotePad* notePad):KeyAction(notePad) {
}
EndKey::~EndKey() {

}

void EndKey::Action() {
	Line* line = (Line*)this->notePad->GetLine();
	Long column = line->Last();
	notePad->SetLine(line);
}
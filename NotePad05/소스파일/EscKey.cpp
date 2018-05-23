//EscKey.cpp

#include "EscKey.h"
#include "NotePad.h"

EscKey::EscKey(NotePad* notePad) :KeyAction(notePad) {

}

EscKey::~EscKey() {

}

void EscKey::Action() {
	this->notePad->SetIsComposition(FALSE);
}
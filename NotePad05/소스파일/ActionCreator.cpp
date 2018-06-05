//ActionCreator.cpp

#include "ActionCreator.h"
#include <afxwin.h>
#include "KeyAction.h"
#include "NotePad.h"
#include "HomeKey.h"
#include "EndKey.h"
#include "LeftKey.h"
#include "RightKey.h"
#include "UpKey.h"
#include "DownKey.h"
#include "PriorKey.h"
#include "NextKey.h"
#include "BackSpaceKey.h"
#include "DeleteKey.h"
#include "EscKey.h"
#include "IntervalRightKey.h"


ActionCreator::ActionCreator() {
	this->keyAction = 0;
}

ActionCreator::~ActionCreator() {
	if (this->keyAction != 0) {
		delete this->keyAction;
		this->keyAction = 0;
	}
}

KeyAction* ActionCreator::Create(NotePad* notePad, UINT nChar) {


	switch (nChar)
	{
	case VK_PRIOR:
		this->keyAction = new PriorKey(notePad);
		break;
	case VK_NEXT:
		this->keyAction = new NextKey(notePad);
		break;
	case VK_HOME:
		this->keyAction = new HomeKey(notePad);
		break;
	case VK_END:
		this->keyAction = new EndKey(notePad);
		break;
	case VK_LEFT:
		this->keyAction = new LeftKey(notePad);
		break;
	case VK_RIGHT:
		this->keyAction = new RightKey(notePad);
		break;
	case VK_UP:
		this->keyAction = new UpKey(notePad);
		break;
	case VK_DOWN:
		this->keyAction = new DownKey(notePad);
		break;
	case VK_DELETE:
		this->keyAction = new DeleteKey(notePad);
		break;
	case VK_BACK:
		this->keyAction = new BackSpaceKey(notePad);
		break;
	case VK_ESCAPE:
		this->keyAction = new EscKey(notePad);
		break;
	
	default:
		break;
	}
	
	return this->keyAction;
}
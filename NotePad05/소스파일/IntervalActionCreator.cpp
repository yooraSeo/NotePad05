//IntervalActionCreator.cpp

#include "IntervalActionCreator.h"
#include "IntervalKeyAction.h"
#include <afxwin.h>
#include "IntervalRightKey.h"
#include "NotePad.h"
#include "IntervalLeftKey.h"
#include "IntervalHomeKey.h"
#include "IntervalEndKey.h"

IntervalActionCreator::IntervalActionCreator() {
	this->intervalKeyAction = 0;
}

IntervalActionCreator::~IntervalActionCreator() {
	if (this->intervalKeyAction != 0) {
		delete this->intervalKeyAction;
		this->intervalKeyAction = 0;
	}
}

IntervalKeyAction* IntervalActionCreator::Create(NotePad* notePad, UINT nChar) {
	switch (nChar)
	{
	case VK_RIGHT:
		this->intervalKeyAction = new IntervalRightKey(notePad);
		break;
	case VK_LEFT:
		this->intervalKeyAction = new IntervalLeftKey(notePad);
		break;
	case VK_HOME:
		this->intervalKeyAction = new IntervalHomeKey(notePad);
		break;
	case VK_END:
		this->intervalKeyAction = new IntervalEndKey(notePad);
		break;
	default:
		break;
	}
	return this->intervalKeyAction;
}
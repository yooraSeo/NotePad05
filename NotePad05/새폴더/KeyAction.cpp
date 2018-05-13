//KeyAction.cpp
/*
파일명 : KeyAction.cpp
작성일자 : 2018년 05월 03일
작성자 : 임정훈
기능 : 키보드 기능 키들의 입력을 담당하여 해당 기능을 처리
수정 : -
*/
#include "KeyAction.h"
#include "NotePad.h"
#include "Positioner.h"
#include "CharacterMatrixSingletonPattern.h"
#include "Paper.h"
#include "Line.h"
#include "CharacterMatrix.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
KeyAction::KeyAction() {
	this->notePad = 0;
	this->positioner = 0;
}
KeyAction::KeyAction(NotePad* notePad) {
	this->notePad = notePad;
	this->positioner = new Positioner();
}
KeyAction::~KeyAction() {

}

void KeyAction::Action(UINT nChar) {
	CharacterMatrix* characterMatrix = CharacterMatrixSingletonPattern::Instance(notePad);
	CPoint point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	this->row = paper->GetCurrent();
	this->column = line->GetCurrent();
	if (nChar == VK_HOME) {
		this->column = line->First();
		line->SetCurrent(this->column);
		this->notePad->SetLine(line);
		this->notePad->Notify();
		this->notePad->Invalidate();
	}
	else if (nChar == VK_END) {
		//this->notePad->SetLine(line);
		this->column = line->Last();
		line->SetCurrent(this->column);
		this->notePad->SetLine(line);
		this->notePad->Notify();
		this->notePad->Invalidate();
	}
	else if (nChar == VK_LEFT) { //left arrow key		
		if (this->column > 0 || point.x != positioner->GetX(this->notePad, line, this->column)) {
			if (point.x == positioner->GetX(this->notePad, line, this->column)) {
				this->column = line->Prev();
			}
		}
		else if (this->column <= 0 && this->row > 0) {
			this->row = paper->Prev();
			line = (Line*)paper->GetAt(this->row);
			this->notePad->SetPaper(paper);
			this->column = line->Last();
		}
		line->SetCurrent(this->column);
		this->notePad->SetLine(line);
		this->notePad->Notify();
		notePad->Invalidate();
	}

	else if (nChar == VK_RIGHT) { //right arrow key
		if (this->column < line->GetLength() || point.x < this->positioner->GetX(this->notePad,line,line->GetLength())) {
			this->column = line->Next();
		}
		else if (this->column >= line->GetLength() && this->row < paper->GetLength() - 1) {
			this->row = paper->Next();
			line = (Line*)paper->GetAt(this->row);
			this->notePad->SetPaper(paper);
			this->column = line->First();
		}
		line->SetCurrent(this->column);
		this->notePad->SetLine(line);
		this->notePad->Notify();
		this->notePad->Invalidate();
	}

	else if (nChar == VK_UP) { //up arrow key
		if (this->row >= 0) {
			point.x = this->positioner->GetX(this->notePad, line, this->column);
			this->row = paper->Prev();
			line = (Line*)paper->GetAt(this->row);
			Long x = this->positioner->GetX(this->notePad, line, line->GetLength());
			Long i = 0;
			Long prevX = 0;
			if (x > point.x) {
				x = 0;
				while (x < point.x && i < line->GetLength()) {
					prevX = x;
					x = this->positioner->GetX(this->notePad, line, i);
					i++;
				}
				if (point.x - prevX > x - point.x) {
					this->column = i - 1;
				}
				else {
					this->column = i - 2;
				}				
			}
			else {
				if (this->column != line->GetLength() || point.x == x) {
					this->column = line->Last();
				}
			}
			line->SetCurrent(this->column);
			this->notePad->SetLine(line);
			this->notePad->Notify();
			this->notePad->Invalidate();
		}
	}
	else if (nChar == VK_DOWN) { //down arrow key
		if (this->row < paper->GetLength()-1) {
			point.x = this->positioner->GetX(this->notePad, line, this->column);
			this->row = paper->Next();
			line = (Line*)paper->GetAt(this->row);
			Long x = this->positioner->GetX(this->notePad, line, line->GetLength());
			Long i = 0;
			Long prevX = 0;
			if (x > point.x) {
				x = 0;
				while (x < point.x && i < line->GetLength()) {
					prevX = x;
					x = this->positioner->GetX(this->notePad, line, i);
					i++;
				}
				if (point.x - prevX > x - point.x) {
					this->column = i - 1;
				}
				else {
					this->column = i - 2;
				}
			}
			else {
				if (this->column != line->GetLength() || point.x == x) {
					this->column = line->Last();
				}
			}
			line->SetCurrent(this->column);
			this->notePad->SetLine(line);
			this->notePad->Notify();
			this->notePad->Invalidate();
		}
	}
	else if (nChar == VK_PRIOR) { //page up key
		this->column = line->GetCurrent();
		this->row = paper->First();
		this->notePad->SetPaper(paper);
		line = (Line*)paper->GetAt(this->row);
		if (line->GetLength() < this->column) {
			this->column = line->Last();
		}
		line->SetCurrent(this->column);
		this->notePad->SetLine(line);
		this->notePad->Notify();
		this->notePad->Invalidate();
	}
	else if (nChar == VK_NEXT) { //page down key
		this->column = line->GetCurrent();
		this->row = paper->Last();
		this->row = paper->Prev();
		this->notePad->SetPaper(paper);
		line = (Line*)paper->GetAt(this->row);
		if (line->GetLength() < this->column) {
			this->column = line->Last();
		}
		line->SetCurrent(this->column);
		this->notePad->SetLine(line);
		this->notePad->Notify();
		this->notePad->Invalidate();
	}
}




//if (this->row > 0) {
//	Long x = this->positioner->GetX(this->notePad, line, this->column);
//	this->row = paper->Prev();
//	line = (Line*)paper->GetAt(this->row);
//	this->notePad->SetPaper(paper);
//	Long nextX = this->positioner->GetX(this->notePad, line, line->GetLength());
//	Long i = 0;
//	if (x >= nextX) {
//		this->column = line->Last();
//	}
//	else {
//		nextX = 0;
//		while (nextX < x && i < line->GetLength()) {
//			nextX = this->positioner->GetX(this->notePad, line, i);
//			i++;
//		}
//		this->column = i - 1;
//	}
//	this->notePad->SetLine(line);
//	this->notePad->Notify();
//	notePad->Invalidate();
//}
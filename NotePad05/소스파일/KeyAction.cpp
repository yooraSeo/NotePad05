//KeyAction.cpp
/*
파일명 : KeyAction.cpp
작성일자 : 2018년 05월 03일
작성자 : 임정훈
기능 : 키보드 기능 키들의 입력을 담당하여 해당 기능을 처리
수정 : -
*/
#include "KeyAction.h"

KeyAction::KeyAction(NotePad* notePad) {
	this->notePad = notePad;
}

KeyAction::~KeyAction() {
	
}
void KeyAction::Action() {

}




//
//
//#if 0
//void KeyAction::Action(UINT nChar){
//	CPoint point = this->notePad->GetCaretPos();
//	Paper* paper = (Paper*)this->notePad->GetPaper();
//	Line* line = (Line*)this->notePad->GetLine();
//	this->row = paper->GetCurrent();
//	this->column = line->GetCurrent();
//
//	if (nChar == VK_HOME) {
//		this->column = line->First();
//		notePad->SetLine(line);
//		this->notePad->Notify();
//		notePad->Invalidate();
//	}
//	else if (nChar == VK_END) {
//		this->column = line->Last();
//		notePad->SetLine(line);
//		this->notePad->Notify();
//		notePad->Invalidate();
//	}
//	else if (nChar == VK_LEFT) { //left arrow key
//		if (this->column > 0 || point.x != positioner->GetX(notePad,line,this->column)) {
//			if (point.x == positioner->GetX(notePad, line, this->column)) {
//				this->column = line->Prev();
//			}
//		}
//		else if (this->row > 0) {
//			this->row = paper->Prev();
//			line = (Line*)paper->GetAt(this->row);
//			this->column = line->Last();
//			notePad->SetPaper(paper);
//		}
//		notePad->SetLine(line);
//		notePad->Notify();
//		notePad->Invalidate();
//	}
//	else if (nChar == VK_RIGHT) { //right arrow key
//		if (this->column < line->GetLength()) {
//			this->column = line->Next();
//		}
//		else if (this->row < paper->GetLength()-1) {
//			this->row = paper->Next();
//			line = (Line*)paper->GetAt(this->row);
//			this->column = line->First();
//			notePad->SetPaper(paper);
//		}
//		notePad->SetLine(line);
//		notePad->Notify();
//		notePad->Invalidate();
//	}
//	else if (nChar == VK_UP) { //up arrow key
//		if (this->row > 0) {
//			this->column = line->GetCurrent();
//			this->row = paper->Prev();
//			line = (Line*)paper->GetAt(this->row);
//			Long x = point.x;
//			Long leng = line->GetLength();
//			Long temp = 0;
//			Long sum = x - temp;
//			if (this->column <= leng) {
//				if (positioner->GetX(notePad, line, this->column) != x) {
//					Long i = 1;
//					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
//						temp = positioner->GetX(notePad, line, i);
//						if (sum > x - temp) {
//							sum = x - temp;
//						}
//						i++;
//					}
//					if (i > leng) {
//						i = leng;
//					}
//					temp = positioner->GetX(notePad, line, i) - x;
//					if (i <= leng && sum < temp) {
//						this->column = i - 1;
//					}
//					else {
//						this->column = i;
//					}
//					line->SetCurrent(this->column);
//				}
//				else {
//					line->SetCurrent(this->column);
//				}
//			}
//			else {
//				if (positioner->GetX(notePad, line, leng) > x) {
//					Long i = 1;
//					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
//						temp = positioner->GetX(notePad, line, i);
//						if (sum > x - temp) {
//							sum = x - temp;
//						}
//						i++;
//					}
//					if (i > leng) {
//						i = leng;
//					}
//					temp = positioner->GetX(notePad, line, i) - x;
//					if (i <= leng && sum < temp) {
//						this->column = i - 1;
//					}
//					else {
//						this->column = i;
//					}
//					line->SetCurrent(this->column);
//				}
//				else {
//					this->column = line->Last();
//				}
//			}
//		}
//		notePad->SetPaper(paper);
//		notePad->SetLine(line);
//		notePad->Notify();
//		notePad->Invalidate();
//	}
//	else if (nChar == VK_DOWN) { //down arrow key
//		if (this->row < paper->GetLength()-1) {
//			this->column = line->GetCurrent();
//			this->row = paper->Next();
//			line = (Line*)paper->GetAt(this->row);
//			Long x = point.x;
//			Long leng = line->GetLength();
//			Long temp = 0;
//			Long sum = x - temp;
//			if (this->column <= leng) {
//				if (positioner->GetX(notePad, line, this->column) != x) {
//					Long i = 1;
//					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
//						temp = positioner->GetX(notePad, line, i);
//						if (sum > x - temp) {
//							sum = x - temp;
//						}
//						i++;
//					}
//					if (i > leng) {
//						i = leng;
//					}
//					temp = positioner->GetX(notePad, line, i) - x;
//					if (i <= leng && sum < temp ) {
//						this->column = i - 1;
//					}
//					else {
//						this->column = i;
//					}
//					line->SetCurrent(this->column);
//				}
//				else {
//					line->SetCurrent(this->column);
//				}
//			}
//			else {
//				if (positioner->GetX(notePad, line, leng) > x) {
//					Long i = 1;
//					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
//						temp = positioner->GetX(notePad, line, i);
//						if (sum > x - temp) {
//							sum = x - temp;
//						}
//						i++;
//					}
//					if (i > leng) {
//						i = leng;
//					}
//					temp = positioner->GetX(notePad, line, i) - x;
//					if (i <= leng && sum < temp) {
//						this->column = i - 1;
//					}
//					else {
//						this->column = i;
//					}
//					this->column = i;
//					line->SetCurrent(this->column);
//				}
//				else {
//					this->column = line->Last();
//				}
//			}
//		}
//		notePad->SetPaper(paper);
//		notePad->SetLine(line);
//		notePad->Notify();
//		notePad->Invalidate();
//	}
//	else if (nChar == VK_PRIOR) { //page up key
//		if (this->row != 0) {
//			this->column = line->GetCurrent();
//			this->row = paper->First();
//			line = (Line*)paper->GetAt(this->row);
//			if (this->column < line->GetLength()) {
//				line->SetCurrent(this->column);
//			}
//			else {
//				this->column = line->Last();
//			}
//			notePad->SetPaper(paper);
//			notePad->SetLine(line);
//			notePad->Notify();
//			notePad->Invalidate();
//		}
//	}
//	else if (nChar == VK_NEXT) { //page down key
//		if (this->row != paper->GetLength()-1) {
//			this->column = line->GetCurrent();
//			paper->Last();
//			this->row = paper->Prev();
//			line = (Line*)paper->GetAt(this->row);
//			if (this->column < line->GetLength()) {
//				line->SetCurrent(this->column);
//			}
//			else {
//				this->column = line->Last();
//			}
//			notePad->SetPaper(paper);
//			notePad->SetLine(line);
//			notePad->Notify();
//			notePad->Invalidate();
//		}
//	}
//}
//#endif
//
//

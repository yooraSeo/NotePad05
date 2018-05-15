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
#include "Paper.h"
#include "Line.h"
#include "DoubleByteCharacter.h"
#include "SingleByteCharacter.h"
KeyAction::KeyAction() {
	this->notePad = 0;
	this->positioner = 0;
	this->row = 0;
	this->column = 0;
}
KeyAction::KeyAction(NotePad* notePad) {
	this->notePad = notePad;
	this->positioner = new Positioner();
	this->row = notePad->GetPaper()->GetCurrent();
	this->column = notePad->GetLine()->GetCurrent();
}
KeyAction::~KeyAction() {

}
CPoint KeyAction::HomeKey(UINT nChar) {
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->First();
	notePad->SetLine(line);

	this->notePad->Notify();
	notePad->Invalidate();
	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::EndKey(UINT nChar) {
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->Last();
	notePad->SetLine(line);

	this->notePad->Notify();
	notePad->Invalidate();
	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::LeftKey(UINT nChar) {
	point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	this->row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	if (this->column > 0 || point.x != positioner->GetX(notePad, line, this->column)) {
		if (point.x == positioner->GetX(notePad, line, this->column)) {
			this->column = line->Prev();
		}
	}
	else if (this->row > 0) {
		this->row = paper->Prev();
		line = (Line*)paper->GetAt(this->row);
		this->column = line->Last();
		notePad->SetPaper(paper);
	}
	notePad->SetLine(line);
	notePad->Notify();
	notePad->Invalidate();
	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::RightKey(UINT nChar) {
	point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	this->row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	if (this->column < line->GetLength()) {
		this->column = line->Next();
	}
	else if (this->row < paper->GetLength() - 1) {
		this->row = paper->Next();
		line = (Line*)paper->GetAt(this->row);
		this->column = line->First();
		notePad->SetPaper(paper);
	}
	notePad->SetLine(line);
	notePad->Notify();
	notePad->Invalidate();
	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::UpKey(UINT nChar) {
	point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	this->row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	if (this->row > 0) {
		this->column = line->GetCurrent();
		this->row = paper->Prev();
		line = (Line*)paper->GetAt(this->row);
		Long x = point.x;
		Long leng = line->GetLength();
		Long temp = 0;
		Long sum = x - temp;
		if (this->column <= leng) {
			if (positioner->GetX(notePad, line, this->column) != x) {
				Long i = 1;
				while (i <= leng && positioner->GetX(notePad, line, i) < x) {
					temp = positioner->GetX(notePad, line, i);
					if (sum > x - temp) {
						sum = x - temp;
					}
					i++;
				}
				if (i > leng) {
					i = leng;
				}
				temp = positioner->GetX(notePad, line, i) - x;
				if (i <= leng && sum < temp) {
					this->column = i - 1;
				}
				else {
					this->column = i;
				}
				line->SetCurrent(this->column);
			}
			else {
				line->SetCurrent(this->column);
			}
		}
		else {
			if (positioner->GetX(notePad, line, leng) > x) {
				Long i = 1;
				while (i <= leng && positioner->GetX(notePad, line, i) < x) {
					temp = positioner->GetX(notePad, line, i);
					if (sum > x - temp) {
						sum = x - temp;
					}
					i++;
				}
				if (i > leng) {
					i = leng;
				}
				temp = positioner->GetX(notePad, line, i) - x;
				if (i <= leng && sum < temp) {
					this->column = i - 1;
				}
				else {
					this->column = i;
				}
				line->SetCurrent(this->column);
			}
			else {
				this->column = line->Last();
			}
		}
	}
	notePad->SetPaper(paper);
	notePad->SetLine(line);
	notePad->Notify();
	notePad->Invalidate();
	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::DownKey(UINT nChar) {
	point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	this->row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	if (this->row < paper->GetLength() - 1) {
		this->column = line->GetCurrent();
		this->row = paper->Next();
		line = (Line*)paper->GetAt(this->row);
		Long x = point.x;
		Long leng = line->GetLength();
		Long temp = 0;
		Long sum = x - temp;
		if (this->column <= leng) {
			if (positioner->GetX(notePad, line, this->column) != x) {
				Long i = 1;
				while (i <= leng && positioner->GetX(notePad, line, i) < x) {
					temp = positioner->GetX(notePad, line, i);
					if (sum > x - temp) {
						sum = x - temp;
					}
					i++;
				}
				if (i > leng) {
					i = leng;
				}
				temp = positioner->GetX(notePad, line, i) - x;
				if (i <= leng && sum < temp) {
					this->column = i - 1;
				}
				else {
					this->column = i;
				}
				line->SetCurrent(this->column);
			}
			else {
				line->SetCurrent(this->column);
			}
		}
		else {
			if (positioner->GetX(notePad, line, leng) > x) {
				Long i = 1;
				while (i <= leng && positioner->GetX(notePad, line, i) < x) {
					temp = positioner->GetX(notePad, line, i);
					if (sum > x - temp) {
						sum = x - temp;
					}
					i++;
				}
				if (i > leng) {
					i = leng;
				}
				temp = positioner->GetX(notePad, line, i) - x;
				if (i <= leng && sum < temp) {
					this->column = i - 1;
				}
				else {
					this->column = i;
				}
				this->column = i;
				line->SetCurrent(this->column);
			}
			else {
				this->column = line->Last();
			}
		}
	}
	notePad->SetPaper(paper);
	notePad->SetLine(line);
	notePad->Notify();

	notePad->Invalidate();

	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::Priorkey(UINT nChar) {
	this->point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	this->row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	if (this->row != 0) {
		this->column = line->GetCurrent();
		this->row = paper->First();
		line = (Line*)paper->GetAt(this->row);
		if (this->column < line->GetLength()) {
			line->SetCurrent(this->column);
		}
		else {
			this->column = line->Last();
		}
		notePad->SetPaper(paper);
		notePad->SetLine(line);
		notePad->Notify();
		notePad->Invalidate();
		this->point = this->notePad->GetCaretPos();
	}
	return this->point;

}
CPoint KeyAction::NextKey(UINT nChar) {
	this->point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	this->row = paper->GetCurrent();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();

	if (this->row < paper->GetLength() - 1) {
		this->column = line->GetCurrent();
		paper->Last();
		this->row = paper->Prev();
		line = (Line*)paper->GetAt(this->row);
		if (this->column < line->GetLength()) {
			line->SetCurrent(this->column);
		}
		else {
			this->column = line->Last();
		}
		notePad->SetPaper(paper);
		notePad->SetLine(line);
		notePad->Notify();
		notePad->Invalidate();
		this->point = this->notePad->GetCaretPos();
	}
	return this->point;
}

CPoint KeyAction::BackSpaceKey(UINT nChar) {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	this->row = paper->GetCurrent();
	Long lineLeng = line->GetLength();
	
	if (this->column > 0 && this->column <= lineLeng) {
		line->Remove(this->column-1);
	}
	else if (this->column <= 0 && this->row > 0) {
		if (line->GetLength() > 0) {
			Long i = 0;
			Glyph* glyph;
			string  str;
			str = line->MakeString();
			line = (Line*)paper->GetAt(this->row-1);
			Long getCurrent = line->Last();
			char cha[2];
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
			this->column = line->SetCurrent(getCurrent);
			paper->Remove(this->row);
			(this->row)--;
		}
		else {
			paper->Remove(this->row);
			this->row--;
			line = (Line*)paper->GetAt(this->row);
			this->column = line->Last();
			line->SetCurrent(this->column);
		}
		this->notePad->SetPaper(paper);
	}

	notePad->Invalidate();
	this->notePad->SetLine(line);
	this->notePad->Notify();
	this->point = this->notePad->GetCaretPos();
	return this->point;
}
CPoint KeyAction::DeleteKey(UINT nChar) {
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	this->column = line->GetCurrent();
	this->row = paper->GetCurrent();
	
	if (this->column < line->GetLength()) {
		line->Remove(this->column);
		line->Next();
	}
	else if (this->row < paper->GetLength()-1) {
		Long i = 0;
		Glyph* glyph;
		string  str;
		line = (Line*)paper->GetAt(this->row + 1);
		str = line->MakeString();
		line = (Line*)paper->GetAt(this->row);
		Long getCurrent = line->Last();
		char cha[2];
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
		this->column = line->SetCurrent(getCurrent);
		paper->Remove(this->row+1);
		paper->Next();
	}
	this->notePad->SetLine(line);
	this->notePad->Notify();
	this->point = this->notePad->GetCaretPos();
	notePad->Invalidate();
	return this->point;
}
#if 0
void KeyAction::Action(UINT nChar){
	CPoint point = this->notePad->GetCaretPos();
	Paper* paper = (Paper*)this->notePad->GetPaper();
	Line* line = (Line*)this->notePad->GetLine();
	this->row = paper->GetCurrent();
	this->column = line->GetCurrent();

	if (nChar == VK_HOME) {
		this->column = line->First();
		notePad->SetLine(line);
		this->notePad->Notify();
		notePad->Invalidate();
	}
	else if (nChar == VK_END) {
		this->column = line->Last();
		notePad->SetLine(line);
		this->notePad->Notify();
		notePad->Invalidate();
	}
	else if (nChar == VK_LEFT) { //left arrow key
		if (this->column > 0 || point.x != positioner->GetX(notePad,line,this->column)) {
			if (point.x == positioner->GetX(notePad, line, this->column)) {
				this->column = line->Prev();
			}
		}
		else if (this->row > 0) {
			this->row = paper->Prev();
			line = (Line*)paper->GetAt(this->row);
			this->column = line->Last();
			notePad->SetPaper(paper);
		}
		notePad->SetLine(line);
		notePad->Notify();
		notePad->Invalidate();
	}
	else if (nChar == VK_RIGHT) { //right arrow key
		if (this->column < line->GetLength()) {
			this->column = line->Next();
		}
		else if (this->row < paper->GetLength()-1) {
			this->row = paper->Next();
			line = (Line*)paper->GetAt(this->row);
			this->column = line->First();
			notePad->SetPaper(paper);
		}
		notePad->SetLine(line);
		notePad->Notify();
		notePad->Invalidate();
	}
	else if (nChar == VK_UP) { //up arrow key
		if (this->row > 0) {
			this->column = line->GetCurrent();
			this->row = paper->Prev();
			line = (Line*)paper->GetAt(this->row);
			Long x = point.x;
			Long leng = line->GetLength();
			Long temp = 0;
			Long sum = x - temp;
			if (this->column <= leng) {
				if (positioner->GetX(notePad, line, this->column) != x) {
					Long i = 1;
					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
						temp = positioner->GetX(notePad, line, i);
						if (sum > x - temp) {
							sum = x - temp;
						}
						i++;
					}
					if (i > leng) {
						i = leng;
					}
					temp = positioner->GetX(notePad, line, i) - x;
					if (i <= leng && sum < temp) {
						this->column = i - 1;
					}
					else {
						this->column = i;
					}
					line->SetCurrent(this->column);
				}
				else {
					line->SetCurrent(this->column);
				}
			}
			else {
				if (positioner->GetX(notePad, line, leng) > x) {
					Long i = 1;
					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
						temp = positioner->GetX(notePad, line, i);
						if (sum > x - temp) {
							sum = x - temp;
						}
						i++;
					}
					if (i > leng) {
						i = leng;
					}
					temp = positioner->GetX(notePad, line, i) - x;
					if (i <= leng && sum < temp) {
						this->column = i - 1;
					}
					else {
						this->column = i;
					}
					line->SetCurrent(this->column);
				}
				else {
					this->column = line->Last();
				}
			}
		}
		notePad->SetPaper(paper);
		notePad->SetLine(line);
		notePad->Notify();
		notePad->Invalidate();
	}
	else if (nChar == VK_DOWN) { //down arrow key
		if (this->row < paper->GetLength()-1) {
			this->column = line->GetCurrent();
			this->row = paper->Next();
			line = (Line*)paper->GetAt(this->row);
			Long x = point.x;
			Long leng = line->GetLength();
			Long temp = 0;
			Long sum = x - temp;
			if (this->column <= leng) {
				if (positioner->GetX(notePad, line, this->column) != x) {
					Long i = 1;
					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
						temp = positioner->GetX(notePad, line, i);
						if (sum > x - temp) {
							sum = x - temp;
						}
						i++;
					}
					if (i > leng) {
						i = leng;
					}
					temp = positioner->GetX(notePad, line, i) - x;
					if (i <= leng && sum < temp ) {
						this->column = i - 1;
					}
					else {
						this->column = i;
					}
					line->SetCurrent(this->column);
				}
				else {
					line->SetCurrent(this->column);
				}
			}
			else {
				if (positioner->GetX(notePad, line, leng) > x) {
					Long i = 1;
					while (i <= leng && positioner->GetX(notePad, line, i) < x) {
						temp = positioner->GetX(notePad, line, i);
						if (sum > x - temp) {
							sum = x - temp;
						}
						i++;
					}
					if (i > leng) {
						i = leng;
					}
					temp = positioner->GetX(notePad, line, i) - x;
					if (i <= leng && sum < temp) {
						this->column = i - 1;
					}
					else {
						this->column = i;
					}
					this->column = i;
					line->SetCurrent(this->column);
				}
				else {
					this->column = line->Last();
				}
			}
		}
		notePad->SetPaper(paper);
		notePad->SetLine(line);
		notePad->Notify();
		notePad->Invalidate();
	}
	else if (nChar == VK_PRIOR) { //page up key
		if (this->row != 0) {
			this->column = line->GetCurrent();
			this->row = paper->First();
			line = (Line*)paper->GetAt(this->row);
			if (this->column < line->GetLength()) {
				line->SetCurrent(this->column);
			}
			else {
				this->column = line->Last();
			}
			notePad->SetPaper(paper);
			notePad->SetLine(line);
			notePad->Notify();
			notePad->Invalidate();
		}
	}
	else if (nChar == VK_NEXT) { //page down key
		if (this->row != paper->GetLength()-1) {
			this->column = line->GetCurrent();
			paper->Last();
			this->row = paper->Prev();
			line = (Line*)paper->GetAt(this->row);
			if (this->column < line->GetLength()) {
				line->SetCurrent(this->column);
			}
			else {
				this->column = line->Last();
			}
			notePad->SetPaper(paper);
			notePad->SetLine(line);
			notePad->Notify();
			notePad->Invalidate();
		}
	}
}
#endif



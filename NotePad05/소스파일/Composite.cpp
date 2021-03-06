/*
파일명 : Composite.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : paper와 line을 포함하는 추상 클래스로 생성자, 복사생성자, 소멸자, add, getAt 연산자 =정의 (속성: 할당량, 사용량, 현재위치)
수정 : -
*/
//Composite.cpp
#include "Composite.h"

Composite::Composite(Long capacity) :glyphes(capacity) {
	this->capacity = capacity;
	this->length = 0;
	this->current = 0;
}
Composite::Composite(const Composite & source) : glyphes(source.glyphes) {
	Long i = 0;
	Glyph* glyph;
		while (i < source.length) {
			glyph = (const_cast<Composite&>(source)).glyphes.GetAt(i);
			this->glyphes.Modify(i, glyph->Clone());
			i++;
		}
	this->capacity = source.capacity;
	this->length = source.length;
	this->current = source.current;
}

Composite::~Composite() {
	Long i = 0;
	while (i < this->length) {
		delete this->glyphes[i];
		i++;
	}
}
Long Composite::Add(Glyph* glyph) {
	Long index;
	if (this->length < this->capacity) {
		index = this->glyphes.Store(this->length, glyph);
	}
	else {
		index = this->glyphes.AppendFromRear(glyph);
		(this->capacity)++;
	}
	this->current = index;
	(this->length)++;
	return index;
}

Glyph* Composite::GetAt(Long index) {
	return this->glyphes[index];
}

Long Composite::Remove(Long index) {
	if (this->glyphes[index] != 0) {
	delete this->glyphes[index];
	}
	this->glyphes.Delete(index);
	(this->length)--;
	(this->capacity)--;
	(this->current)--;
	return -1;
}
Long Composite::First() {
	this->current = 0;
	return this->current;
}
Long Composite::Prev() {
	if (this->current > 0) {
		(this->current)--;
	}
	return this->current;
}
Long Composite::Next() {
	if (this->current < this->length) {
		(this->current)++;
	}
	return this->current;
}
Long Composite::Last() {
	this->current = this->length;
	return this->current;
}
Long Composite::SetCurrent(Long index) {
	this->current = index;
	return this->current;
}

Composite & Composite::operator=(const Composite & source) {
	Long i = 0;
	Glyph* glyph;
	this->glyphes = source.glyphes;
	while (i < source.length) {
		glyph = (const_cast<Composite&>(source)).glyphes.GetAt(i);
		this->glyphes.Modify(i, glyph->Clone());
		i++;
	}
	this->capacity = source.capacity;
	this->length = source.length;
	this->current = source.current;
	return *this;
}

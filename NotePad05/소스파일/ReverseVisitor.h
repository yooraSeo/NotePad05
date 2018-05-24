//ReverseVisitor.h
#ifndef _REVERSEVISITOR_H
#define _REVERSEVISITOR_H
#include "visitor.h"

class NotePad;
class CDC;
class ReverseVisitor :public Visitor {
public:
	ReverseVisitor(CDC* dc, NotePad* notePad);
	~ReverseVisitor();
	virtual void Visit(Paper* paper);
	virtual void Visit(Line* line);
	virtual void Visit(DoubleByteCharacter* doublsByteCharacter);
	virtual void Visit(SingleByteCharacter* singleByteCharacter);
private:
	CDC * dc;
	NotePad* notePad;
};
#endif // !_REVERSEVISITOR_H


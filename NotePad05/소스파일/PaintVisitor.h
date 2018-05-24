//PaintVisitor.h
#ifndef _PAINTVISITOR_H
#define _PAINTVISITOR_H
#include "Visitor.h"

class CDC;
class NotePad;
class PaintVisitor :public Visitor {
public:
	PaintVisitor(CDC* dc, NotePad* notePad);
	~PaintVisitor();
	virtual void Visit(Paper* paper);
	virtual void Visit(Line* line);
	virtual void Visit(DoubleByteCharacter* doublsByteCharacter);
	virtual void Visit(SingleByteCharacter* singleByteCharacter);
private:
	CDC * dc;
	NotePad* notePad;
};
#endif // !_PAINTVISITOR_H


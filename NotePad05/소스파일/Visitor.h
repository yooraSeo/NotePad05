//Visitor.h

#ifndef _VISITOR_H
#define _VISITOR_H

class Paper;
class Line;
class DoubleByteCharacter;
class SingleByteCharacter;

class Visitor {
public:
	~Visitor();
	virtual void Visit(Paper* paper) = 0;
	virtual void Visit(Line* line) = 0;
	virtual void Visit(DoubleByteCharacter* doublsByteCharacter) = 0;
	virtual void Visit(SingleByteCharacter* singleByteCharacter) = 0;
protected:
	Visitor();
};

#endif // !_VISITOR_H

//Reverse.h

#ifndef _REVERSE_H
#define _REVERSE_H
#include <string>
#include <string.h>
#include <afxwin.h>
using namespace std;

class NotePad;
class Range;
class Reverse
{
public:
	Reverse(CDC* dc, NotePad* notepad);
	~Reverse();
	void ReverseDrow(Range* range);

private:
	CDC * dc;
	NotePad* notePad;
	Range* range;
	string str;
};
#endif // !_REVERSE_H


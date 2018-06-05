//Range.h

#ifndef _RANGE_H
#define _RANGE_H
#include <afxwin.h>
typedef signed long int Long;
class NotePad;
class Positioner;
class Range {
public:
	Range(NotePad* notePad);
	Range(const Range& source);
	~Range();
	Range& operator=(const Range& source);
	void Sum(NotePad* notePad);
	void Reset(NotePad* notePad);
	Long GetStartRow() const;
	Long GetEndRow() const;
	Long GetStartColumn() const;
	Long GetEndColumn() const;
private:
	Long startRow;
	Long endRow;
	Long startColumn;
	Long endColumn;
};
inline Long Range::GetStartRow() const {
	return this->startRow;
}
inline Long Range::GetEndRow() const {
	return this->endRow;
}
inline Long Range::GetStartColumn() const {
	return this->startColumn;
}
inline Long Range::GetEndColumn() const {
	return this->endColumn;
}
#endif // !_RANGE_H


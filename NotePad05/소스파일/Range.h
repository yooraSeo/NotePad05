//Range.h

#ifndef _RANGE_H
#define _RANGE_H
#include <afxwin.h>
typedef signed long int Long;

class NotePad;
class Range {
public:
	Range();
	Range(NotePad* notePad, Long column, Long row);
	Range(NotePad* notePad, CPoint point);
	//Range(NotePad* notePad);
	Range(const Range& source);
	~Range();
	Range& operator=(const Range& source);
	void Calculate();
	Long GetStartRow() const;
	Long GetEndRow() const;
	Long GetStartColumn() const;
	Long GetEndColumn() const;
	CPoint GetPoint() const;
	//Long SetStartRow(Long row);
	//Long SetStartColumn(Long column);
	//Long SetEndRow(Long row);
	//Long SetEndColumn(Long column);
private:
	Long startRow;
	Long endRow;
	Long startColumn;
	Long endColumn;
	CPoint point;
	NotePad *notePad;
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
inline CPoint Range::GetPoint() const {
	return this->point;
}

//inline Long Range::SetStartRow(Long row) {
//	this->startRow = row;
//	return this->startRow;
//}
//inline Long Range::SetStartColumn(Long column) {
//	this->startColumn = column;
//	return this->startColumn;
//}
//inline Long Range::SetEndRow(Long row) {
//	this->endRow = row;
//	return this->endRow;
//}
//inline Long Range::SetEndColumn(Long column) {
//	this->endColumn = column;
//	return this->endColumn;
//}
#endif // !_RANGE_H


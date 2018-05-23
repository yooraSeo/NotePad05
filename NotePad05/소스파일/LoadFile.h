//LoadFile.h
#ifndef _LOADFILE_H
#define _LOADFILE_H
#include <string>
using namespace std;
class NotePad;
class Glyph;
class LoadFile {
public:
	LoadFile(NotePad* notePad, string name);
	~LoadFile();
private:
	NotePad * notePad;
	string name;
};
#endif // !_LOADFILE_H


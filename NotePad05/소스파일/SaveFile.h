//SaveFile.h
#ifndef _SAVEFILE_H
#define _SAVEFILE_H
#include <string>
using namespace std;
class Glyph;
class SaveFile {
public:
	SaveFile(string name, Glyph* paper);
	~SaveFile();
private:
	string name;
	Glyph* paper;
};
#endif // !_SAVEFILE_H

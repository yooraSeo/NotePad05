//IntervalKeyAction.h

#ifndef _INTERVALKEYACTION_H
#define _INTERVALKEYACTION_H
typedef signed long int Long;
class NotePad;
class IntervalKeyAction
{
public:
	IntervalKeyAction(NotePad* notePad);
	~IntervalKeyAction();
	virtual void IntervalAction() = 0;
	Long* GetSymbols() const;
private:
	Long symbols[13];
	NotePad* notePad;
};
inline Long* IntervalKeyAction::GetSymbols() const {
	return const_cast<Long*>(this->symbols);
}
#endif // !_INTERVALKEYACTION_H
/*
파일명 : NotePadApp.h
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : 노트패드 CFrameWnd 출력 인스턴스 선언
수정 : -
*/
//NotePadApp.h
#ifndef _NOTEPADAPP_H
#define _NOTEPADAPP_H
#include <afxwin.h>

class NotePadApp:public CWinApp {
public:
	virtual BOOL InitInstance();
};
#endif // !_NOTEPADAPP_H

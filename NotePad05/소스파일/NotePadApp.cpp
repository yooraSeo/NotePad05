/*
파일명 : NotePadApp.cpp
작성일자 : 2018년 04월 24일
작성자 : 서유라
기능 : 노트패드 CFrameWnd 출력 인스턴스 정의
수정 : -
*/
//NotePadApp.cpp
#include "NotePadApp.h"
#include "NotePad.h"
BOOL NotePadApp::InitInstance() {
	NotePad* notePad = new NotePad;
	DWORD dwStyle = WS_OVERLAPPEDWINDOW | WS_VSCROLL;
	notePad->Create(NULL, (LPCTSTR)"새메모장", dwStyle);
	notePad->ShowWindow(this->m_nCmdShow);
	this->m_pMainWnd = notePad;
	return TRUE;
}
NotePadApp notePadApp;
/*
���ϸ� : NotePadApp.cpp
�ۼ����� : 2018�� 04�� 24��
�ۼ��� : ������
��� : ��Ʈ�е� CFrameWnd ��� �ν��Ͻ� ����
���� : -
*/
//NotePadApp.cpp
#include "NotePadApp.h"
#include "NotePad.h"
BOOL NotePadApp::InitInstance() {
	NotePad* notePad = new NotePad;
	DWORD dwStyle = WS_OVERLAPPEDWINDOW | WS_VSCROLL;
	notePad->Create(NULL, (LPCTSTR)"���޸���", dwStyle);
	notePad->ShowWindow(this->m_nCmdShow);
	this->m_pMainWnd = notePad;
	return TRUE;
}
NotePadApp notePadApp;

// winmineFZ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CwinmineFZApp: 
// �йش����ʵ�֣������ winmineFZ.cpp
//

class CwinmineFZApp : public CWinApp
{
public:
	CwinmineFZApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CwinmineFZApp theApp;
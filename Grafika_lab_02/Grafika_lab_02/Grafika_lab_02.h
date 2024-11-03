
// Grafika_lab_02.h : main header file for the Grafika_lab_02 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGrafikalab02App:
// See Grafika_lab_02.cpp for the implementation of this class
//

class CGrafikalab02App : public CWinApp
{
public:
	CGrafikalab02App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGrafikalab02App theApp;

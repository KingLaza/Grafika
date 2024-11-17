
// IND_18569.h : main header file for the IND_18569 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CIND18569App:
// See IND_18569.cpp for the implementation of this class
//

class CIND18569App : public CWinApp
{
public:
	CIND18569App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIND18569App theApp;

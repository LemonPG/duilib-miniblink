#include <windows.h>
#include "MainFrameWnd.h"
#include "WkeWebkitUI.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	CWkeWebkitUI::WkeWebkit_Init();

	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("\\skin"));

	CMainFrameWnd* pFrame = new CMainFrameWnd();
	if( pFrame == NULL ) return 0;
	pFrame->Create(NULL, _T("MiniblinkBrowser"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 800, 572);
	pFrame->CenterWindow();
	::ShowWindow(*pFrame, SW_SHOW);

	CPaintManagerUI::MessageLoop();

	CWkeWebkitUI::WkeWebkit_Shutdown();
	return 0;
}
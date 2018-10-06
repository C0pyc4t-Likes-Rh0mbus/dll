#include "stdio.h"
#include "windows.h"

#pragma comment(lib, "kernel32.dll")

DWORD WINAPI ThreadProc(LPVOID lParam)
{
	MessageBox(NULL,"hooking Success!","alarm",MB_OK);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	HANDLE hThread = NULL;

	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
			CloseHandle(hThread);
			break;
	}
	return TRUE;
}

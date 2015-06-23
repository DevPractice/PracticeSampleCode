// CreateProc.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include <Windows.h>
#include <iostream>
using namespace std;			


int _tmain(int argc, _TCHAR* argv[])
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si = { sizeof(si) }
	;
	TCHAR name[] = _T("notepad");
	BOOL success = CreateProcessW(nullptr, name, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
	if (success) {

		cout << "PID: " <<pi.dwProcessId << endl;
		cout << "hProcess:" << pi.hProcess << endl;

		WaitForSingleObject(pi.hProcess, INFINITE);
		DWORD code;
		GetExitCodeProcess(pi.hProcess, &code);
	}
	else
	{
		cout << GetLastError() << endl;
	}
	return 0;
}


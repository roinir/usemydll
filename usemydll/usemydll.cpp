#include <iostream>
#include "windows.h"
#define LIBRARY "C:\\Users\\roini\\source\\repos\\mylibdll\\Release\\mylibdll.dll"
//#define LIBRARY "C:\\Users\\roini\\Downloads\\injection\\injection\\my_awesome_dll.dll"

typedef void(*PFUNC)(void);

int main()
{
	/*
	HMODULE hModule = LoadLibraryA(LIBRARY);
	if (NULL == hModule) {
		printf("Failed to load DLL\n");
		return 1;
	}
	PFUNC pFunc = (PFUNC)GetProcAddress(hModule, "TextBox");
	if (NULL != pFunc) {
		(*pFunc)();
	}
	else {
		printf("Failed to load function\n");
		return 1;
	}
	*/
	

	HANDLE processHandle = OpenProcess(THREAD_ALL_ACCESS, true, 30020);
	std::cout << "Process handle: " << processHandle << "\n";
	LPSECURITY_ATTRIBUTES securityDescriptor = NULL;
	std::cout << "securityDescriptor: " << securityDescriptor << "\n";
	SIZE_T stackSize = 150000;
	std::cout << "stackSize: " << stackSize << "\n";
	LPTHREAD_START_ROUTINE appDefinedFunc = (LPTHREAD_START_ROUTINE)&LoadLibraryA;
	std::cout << "appDefinedFunc: " << appDefinedFunc << "\n";
	CONST CHAR* argText = LIBRARY;
	LPVOID arg = LPVOID(argText);
	appDefinedFunc(arg);
	std::cout << "arg: " << arg << "\n";
	DWORD flags = NULL;
	LPDWORD threadID = NULL;

	HANDLE threaHandle = CreateRemoteThread(processHandle, securityDescriptor, stackSize, appDefinedFunc, arg, flags, threadID);
	printf("The error code is: %d\n", GetLastError());
	std::cout << "thread id: " << threadID << "\n";
	std::cout << "thread handle: " << threaHandle << "\n";
	std::cout << "thread id with function: " << GetThreadId(threaHandle) << "\n";

	//CloseHandle(processHandle); //TODO don't forget to close the handle
	

	//std::cout << "Which process would you like to inject into?(process id)"

	//std::cin >> 
	//BOOL injectDLL = WriteProcessMemory(hProcess, lpBaseAdderess, pFunc, sizeof(pFunc), NULL);

	return 0;
}

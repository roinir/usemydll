#include <iostream>
#include "windows.h"
#define LIBRARY "C:\\Users\\roini\\source\\repos\\mylibdll\\Release\\mylibdll.dll"

typedef void(*PFUNC)(void);

int main()
{
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
	return 0;
}

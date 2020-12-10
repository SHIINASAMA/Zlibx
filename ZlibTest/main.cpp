#include <stdio.h>
#include "../Zlibx/ZString.h"
#include "../Zlibx/ZThread.h"

DWORD WINAPI Print(LPVOID)
{
	for (int i = 0; i < 100; i++)
	{
		printf("[Client Thread] %3d\n", i);
	}
	return 0;
}

int main()
{
	ZThread* t = new ZThread(Print, MAKEPARAM(0));
	t->Run();

	for (int i = 0; i < 100; i++)
	{
		printf("[Main\tThread] %3d\n", i);
	}
	getchar();
	return 0;
}
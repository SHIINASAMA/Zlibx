#include <stdio.h>
#include "../Zlibx/ZString.h"

int main() {
	ZString str = L"Hello";
	wprintf_s(str);
	getchar();
	return 0;
}
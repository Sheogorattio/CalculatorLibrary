#include<iostream>
#include<windows.h>
#include<tchar.h>

using namespace std;

typedef void (*fptr) ();

int main() {
	HINSTANCE hInstLib = LoadLibrary(TEXT("CalculatorLibrary.dll"));

	if (!hInstLib) {
		cout << "Can`t load library DllTest.dll" << endl;
		return 0;
	}
	fptr calculator = (fptr)GetProcAddress(hInstLib, "CalcBody");
	if (!calculator)
	{
		cout << "Can`t load function" << endl;
	}
	else
	{
		calculator();
	}

	FreeLibrary(hInstLib);
}
#include "pch.h"
#include <iostream>
using namespace std;
#include "Pachead.h"
#include <Windows.h>


int main()
{
	Pachead first;

	while (1) {
		first.ShowConsoleCursor(false);
		first.Draw();
		first.Direction();
		first.Logic();
		Sleep(100);
	}
	

	return 0;
}

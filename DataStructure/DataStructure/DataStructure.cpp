// DataStructure.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

// StdClass
#include "stdafx.h"
#include <time.h>
#include <crtdbg.h>

// MyClass
#include "BaseArray.h"


int Compare(const int& rA, const int& rB)
{
	if (rA > rB)
		return 1;
	else if (rA < rB)
		return -1;
	else
		return 0;
}
//int(*compare)(const T&, const T&)

int main()
{
	srand(unsigned int(time(nullptr)));

	CBaseArray cBaseArray(10, true); 

	cout << "--------------Before----------" << endl;
	cBaseArray.Render();


	cBaseArray.Degree();
	cBaseArray.Render();

	cout << "--------------After----------" << endl;
	cBaseArray.Render();

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}
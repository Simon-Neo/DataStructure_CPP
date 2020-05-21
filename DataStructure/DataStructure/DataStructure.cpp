// DataStructure.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

// StdClass
#include "stdafx.h"
#include <time.h>
#include <crtdbg.h>

// MyClass
#include "BaseArray.h"
#include "Set.h"


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
	
	CSet* pSet_A = new CSet(5);

	pSet_A->Add(99);
	pSet_A->Add(7);
	pSet_A->Add(0);
	pSet_A->Add(5);


	cout << "AAAAAAAAAA" << endl;
	pSet_A->Print();

	CSet* pSet_B = new CSet(7);
	pSet_B->Add(1);
	pSet_B->Add(7);
	pSet_B->Add(55);
	pSet_B->Add(8);
	pSet_B->Add(99);
	pSet_B->Add(77);
	cout << "BBBBBBB" << endl;
	pSet_B->Print();
	
	//cout << "Equal = " << (pSet_B->Equal(*pSet_A) ? "Equal" : "Not Equal") << endl;

	if (pSet_B->IsMember(55) == -1)
		cout << "Is not in" << endl;
	else
		cout << "Is in" << endl;


	Safe_Delete(pSet_A);
	Safe_Delete(pSet_B);

	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}
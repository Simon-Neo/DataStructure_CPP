// DataStructure.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

// StdClass
#include "stdafx.h"
#include <time.h>
#include <crtdbg.h>

// MyClass
#include "BaseArray.h"
#include "Set.h"
#include "BitSet.h"


int Compare(const int& rA, const int& rB)
{
	if (rA > rB)
		return 1;
	else if (rA < rB)
		return -1;
	else
		return 0;
}

int main()
{
	//_CrtSetBreakAlloc(281);
	srand(unsigned int(time(nullptr)));
	
	CBitSet cBitA;
	cBitA.Add(1);
	cBitA.Add(2);
	cBitA.Add(3);
	cBitA.Add(7);

	cBitA.Print();

	CBitSet cBitB;
	cBitB.Add(1);
	cBitB.Add(2);
	cBitB.Add(9);
	cBitB.Add(8);


	cBitB.Print();

	cBitA.SymmetricDifference(cBitB);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}
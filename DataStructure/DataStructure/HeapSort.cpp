#include "stdafx.h"
#include "HeapSort.h"
#include <math.h>

CHeapSort::CHeapSort()
{
}


CHeapSort::~CHeapSort()
{
}

#ifdef HEAP_RECUR

void CHeapSort::Heap(int * piArray, int iSize, int iNowIndex)
{
	if (0 > iNowIndex - 1)
		return;
	int iRootIndex = (iNowIndex - 1) / 2;

	int iBiggerIndex = 0;
	int iBeginCheckValue = 0;

	// 짝수 오른쪽
	if (iNowIndex % 2 == 0)
	{
		iBiggerIndex =
			piArray[iNowIndex - 1] < piArray[iNowIndex] ? iNowIndex : iNowIndex - 1;
	}
	else
	{
		// 홀수일경우 그러니까 마지막에 혼자 있는 브렌취 뜻함.
		iBiggerIndex = iNowIndex;
		iBeginCheckValue = 1;
	}

	// Swap
	if (piArray[iBiggerIndex] > piArray[iRootIndex])
	{
		// Render Test
		//cout << "Now Index = " << iNowIndex << endl;
		//Render(piArray, iSize);

		Swap(piArray[iBiggerIndex], piArray[iRootIndex]);
		// 스웝 되면 밑부분 검사하는 함수 추가해야함.
		DownHeap(piArray, iSize, iBiggerIndex);
	}

	Heap(piArray, iSize, iNowIndex - 2 + iBeginCheckValue);


}

void CHeapSort::DownHeap(int * piArray, int iSize, int iNowIndex)
{
	int iL_Child = iNowIndex * 2 + 1;
	int iR_Child = iL_Child + 1;

	if (iL_Child >= iSize)
		return;
	else if (iR_Child >= iSize)
	{
		// 왼쪽만 살아있는 경우.
		if (piArray[iNowIndex] < piArray[iL_Child])
			Swap(piArray[iNowIndex], piArray[iL_Child]);
		return;
	}

	int iHighValIndex = piArray[iL_Child] > piArray[iR_Child] ? iL_Child : iR_Child;
	if (piArray[iNowIndex] < piArray[iHighValIndex])
	{
		//cout << "DownHEap" << endl;
		//Render(piArray, iSize);

		Swap(piArray[iHighValIndex], piArray[iNowIndex]);
		DownHeap(piArray, iSize, iHighValIndex);
	}
}

void CHeapSort::ArrangeHeap(int * piArray, int iSize)
{
	if (nullptr == piArray)
		return;
	int iIndex = iSize - 1;
	while (iIndex > 0)
	{
		Swap(piArray[0], piArray[iIndex]);
		DownHeap(piArray, iIndex, 0);
		--iIndex;
	}
}

#else
void CHeapSort::HEAP(int piArray[], int iSize)
{
	for (int i = (iSize - 1) / 2; i >= 0; --i)
		DOWN_HEAP(piArray, i, iSize - 1);

	for (int i = iSize - 1; i > 0; --i) // 9 8 7 6 5 4 3 2 1 
	{
		Swap(piArray[0], piArray[i]);
		DOWN_HEAP(piArray, 0, i - 1);
	//	Render(piArray, iSize);
	}
}

void CHeapSort::DOWN_HEAP(int piArray[], int iStart, int iEnd)
{
	int iChild = 0;
	int cL = 0;
	int cR = 0;

	int iTest = 0;
	for (int iParent = iStart; iParent < (iEnd  + 1)/ 2; iParent = iChild)
	{
		iTest = (iEnd - 1) / 2;

		cL = iParent * 2 + 1; 
		cR = cL + 1;

		iChild = (cR <= iEnd && piArray[cR] > piArray[cL]) ? cR : cL;

		if (piArray[iChild] > piArray[iParent])
			Swap(piArray[iChild], piArray[iParent]);
	}
}

#endif // HEAP_RECUR


int CHeapSort::Pow2(int iSquare)
{
	int iResult = 1;
	for (int i = 0; i < iSquare; ++i)
	{
		iResult *= 2;
	}
	return iResult;
}


/// 이진트리 시도했는데 끝까지는 못함. 나중에 제대로 다시 또 시도하길. 돈기법
void CHeapSort::Render(int * piArray, int iSize)
{
	if (nullptr == piArray || 0 >= iSize)
		return;

	cout << "--------------------------" << endl;

	int iMaxLine = 1;
	int iAllIndex = iSize;
	while (iAllIndex /= 2)
		++iMaxLine;

	iAllIndex = 0;
	int iHoriMax = 1;
	int iBlankMax = 0;
	for (int i = 0 ; i < iMaxLine; ++i)
	{

		iBlankMax = Pow2(iMaxLine - i) - 2;
		for (int k = 0; k <= iBlankMax; ++k)
			cout << " ";

		for (int j = 0; j < iHoriMax; ++j)
		{
			if (iAllIndex >= iSize)
			{
				cout << endl;
				return;
			}

			piArray[iAllIndex] / 10 <= 0 ? 
				cout << "0" << piArray[iAllIndex ++] 
				:
				cout << piArray[iAllIndex ++];

			iBlankMax = Pow2(iMaxLine - i + 1) - 2;
			for (int k = 0; k <= iBlankMax; ++k)
				cout << " ";
		}

		iHoriMax *= 2;
		cout << endl;
	}

		// ↙ ↘

}


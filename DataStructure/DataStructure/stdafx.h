// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#pragma comment(lib, "user32.lib")

using namespace std;



typedef unsigned long BITSET;

template<typename T>
static void Safe_Delete(T *& rpPtr, bool bIsArray = false)
{
	if (nullptr != rpPtr)
	{
		if (bIsArray)
			delete[] rpPtr;
		else
			delete rpPtr;

		rpPtr = nullptr;
	}
}

template<typename T>
static inline void Swap(T & rA, T & rB)
{
	T tTemp = rA;
	rA = rB;
	rB = tTemp;
}

template<typename T>
static void Array_Render(const T pArray[], int iSize = -1)
{
	cout << "{";
	for (int i = 0; i < iSize - 1; ++i)
	{
		cout << pArray[i] << " ";
	}
	cout <<pArray[iSize - 1] << "}" << endl;
}
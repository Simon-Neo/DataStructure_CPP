// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
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
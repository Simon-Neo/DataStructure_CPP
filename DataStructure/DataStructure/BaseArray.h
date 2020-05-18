#pragma once

#include "MergerSort.h"
#include "HeapSort.h"
#include "DegreeSort.h"

class CBaseArray
{

public:
	CBaseArray(int, bool);
	~CBaseArray();

public:
	void Render();

	// Sort
	void Heap();
	void Degree();

private:
	void Release();
	void InitRandVal();
	bool IsEmpty();

private:
	int* m_pArray = nullptr;
	int m_iSize = 0;

	CHeapSort* m_pHeapSort = nullptr;
	CDegreeSort* m_pDegreeSrot = nullptr;

};


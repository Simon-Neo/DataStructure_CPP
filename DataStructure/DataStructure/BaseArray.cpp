#include "stdafx.h"
#include "BaseArray.h"


#define ENTER_VALUE


CBaseArray::CBaseArray(int iSize, bool bIsRandInitVal)
{
	if (nullptr != m_pArray)
		Release();

#ifdef ENTER_VALUE
	m_pArray = new int[iSize] {7, 9, 7, 7, 9, 8, 9, 6, 8, 10};
	//{ 5, 6, 4, 8, 3, 7, 9, 0, 1, 5, 2, 3 };
	if (nullptr == m_pArray)
	{
		cout << "CBaseArray::CBaseArray(int iSize) _. HeapAllocation Fail" << endl;
		return;
	}
#else
	memset(m_pArray, 0, sizeof(m_pArray[0]) * iSize);
	if (bIsRandInitVal)
		InitRandVal();
#endif
	m_iSize = iSize;

	//if (nullptr == m_pMerger)
	//	m_pMerger = new CMergerSort;


	//================================================
	// Heap
	if (nullptr == m_pHeapSort)
		m_pHeapSort = new CHeapSort;

	// Degree
	if (nullptr == m_pDegreeSrot)
		m_pDegreeSrot = new CDegreeSort(m_pArray, iSize);

}

CBaseArray::~CBaseArray()
{
	Release();
}

void CBaseArray::Release()
{
	Safe_Delete(m_pArray, true);

	// Heap
	Safe_Delete(m_pHeapSort);

	// Degree
	Safe_Delete(m_pDegreeSrot);

	m_iSize = 0;
}

void CBaseArray::InitRandVal()
{
	if (IsEmpty())
		return;

	for (int i = 0; i < m_iSize; ++i)
		m_pArray[i] = rand() % 11;
}

void CBaseArray::Render()
{
	if (IsEmpty())
		return;
	for (int i = 0; i < m_iSize; ++i)
		cout << m_pArray[i] << " ";
	cout << endl;
}

void CBaseArray::Heap()
{
	if (nullptr == m_pHeapSort)
	{
		cout << "m_pHeapSort == nullptr" << endl;
		return;
	}

#ifdef HEAP_RECUR
	m_pHeapSort->Heap(m_pArray, m_iSize, m_iSize - 1);

	m_pHeapSort->ArrangeHeap(m_pArray, m_iSize);
#else
	m_pHeapSort->HEAP(m_pArray, m_iSize);
#endif // HEAP_RECUR



	m_pHeapSort->Render(m_pArray, m_iSize);
}

void CBaseArray::Degree()
{
	if (nullptr == m_pDegreeSrot)
	{
		m_pDegreeSrot = new CDegreeSort(m_pArray, m_iSize);
	}

	m_pDegreeSrot->Sort(m_pArray, m_iSize);
}


bool CBaseArray::IsEmpty()
{
	if (0 >= m_iSize || nullptr == m_pArray)
		return true;

	return false;
}


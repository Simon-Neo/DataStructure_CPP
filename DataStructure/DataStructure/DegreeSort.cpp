#include "stdafx.h"
#include "DegreeSort.h"

CDegreeSort::CDegreeSort(int pArray[], int iSize)
{
	Release();

	Max(pArray, iSize);
	Min(pArray, iSize);

	m_iHeapSize = (m_iMax - m_iMin) + 1;
	m_pCumulateArray = new int[m_iHeapSize];
	memset(m_pCumulateArray, 0, sizeof(int) * (m_iHeapSize));
	
	
	m_pArrangeArray = new int[iSize];
	memset(m_pArrangeArray, 0, sizeof(int) * (iSize));
}

CDegreeSort::~CDegreeSort()
{
	Release();
}

void CDegreeSort::Sort(int pArray[], int iSize)
{
	int i = 0;

	cout << "Make Frequency Table----------------------" << endl;
	for (i = iSize - 1; i >= 0; --i)
	{
		++m_pCumulateArray[pArray[i] - m_iMin];
		Array_Render(m_pCumulateArray, m_iHeapSize);
	}
	
	cout << "Add Frequency Table----------------------" << endl;
	for (i = 1; i < m_iHeapSize ; ++i)
	{
		m_pCumulateArray[i] += m_pCumulateArray[i - 1];
		Array_Render(m_pCumulateArray, m_iHeapSize);
	}

	cout << "Object Table----------------------" << endl;
	for (i = iSize - 1; i >= 0; --i)
	{
		m_pArrangeArray[--m_pCumulateArray[pArray[i] - m_iMin]] = pArray[i];
		Array_Render(m_pArrangeArray, iSize );
	}

	memcpy(pArray, m_pArrangeArray, sizeof(int) * iSize);
}

void CDegreeSort::Release()
{
	Safe_Delete(m_pCumulateArray);
	Safe_Delete(m_pArrangeArray);
	m_iMax = 0;
	m_iMin = 0;
	m_iHeapSize = 0;
}

void CDegreeSort::Max(const int pArray[], int iSize)
{
	if (pArray == nullptr)
		return;

	for (int i = 0; i < iSize; ++i)
		if (m_iMax < pArray[i])
			m_iMax = pArray[i];
}

void CDegreeSort::Min(const int pArray[], int iSize)
{
	if (pArray == nullptr)
		return;

	m_iMin = pArray[0];

	for (int i = 1; i < iSize; ++i)
		if (m_iMin > pArray[i])
			m_iMin = pArray[i];
}

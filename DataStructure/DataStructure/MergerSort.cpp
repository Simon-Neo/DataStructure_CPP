#include "stdafx.h"
#include "MergerSort.h"



template<typename T>
CMergerSort<T>::CMergerSort()
{
}

template<typename T>
CMergerSort<T>::~CMergerSort()
{
	Release();
}

//void CMergerSort::MergerSort(int* piArray, int iSize)
//{
//	Release();
//
//	Malloc(iSize);
//	
//	Merger(piArray, 0, iSize - 1);
//	
//}

//void CMergerSort::Merger(int* piArray, int iL, int iR )
//{
//	if (iL >= iR)
//		return;
//
//	int iMid = (iR + iL) / 2;
//
//	int iBuffIndex = 0;
//	int iArrIndex = iL , iRightIndex = iL;
//
//	Merger(piArray, iL, iMid);
//
//	Merger(piArray, iMid + 1, iR);
//
//	while (iRightIndex <= iMid)
//		m_piBuffer[iBuffIndex++] = piArray[iRightIndex++];
//
//	int iBuffSize = iBuffIndex;
//	iBuffIndex = 0;
//
//	while (iRightIndex <= iR && iBuffIndex < iBuffSize)
//	{
//		if (m_piBuffer[iBuffIndex] < piArray[iRightIndex])
//			piArray[iArrIndex++] = m_piBuffer[iBuffIndex++];
//		else
//			piArray[iArrIndex++] = piArray[iRightIndex++];
//	}
//
//	while (iBuffIndex < iBuffSize)
//		piArray[iArrIndex++] = m_piBuffer[iBuffIndex++];
//}

template<typename T>
void CMergerSort<T>::merger(T * pArray, int iL, int iR,
	int(*compare)(const T&, const T&))
{
	if (nullptr == pArray)
		return;
	if (iL >= iR)
		return;

	int iMid = (iR + iL) / 2;

	int iBuffIndex = 0;
	int iArrIndex = iL, iRightIndex = iL;

	Merger(piArray, iL, iMid);

	Merger(piArray, iMid + 1, iR);

	while (iRightIndex <= iMid)
		m_piBuffer[iBuffIndex++] = piArray[iRightIndex++];

	int iBuffSize = iBuffIndex;
	iBuffIndex = 0;

	while (iRightIndex <= iR && iBuffIndex < iBuffSize)
	{
		if(1 == compare(m_piBuffer[iBuffIndex], piArray[iRightIndex]))
			piArray[iArrIndex++] = m_piBuffer[iBuffIndex++];
		else
			piArray[iArrIndex++] = piArray[iRightIndex++];
	}

	while (iBuffIndex < iBuffSize)
		piArray[iArrIndex++] = m_piBuffer[iBuffIndex++];
}

template<typename T>
void CMergerSort<T>::m_sort(T * pArray, size_t iSize, 
	int(*compare)(const T&, const T&))
{
	Release();
	Malloc(iSize);
	merger(pArray, 0, iSize - 1, compare);
}


template<typename T>
void CMergerSort<T>::Safe_Delete(T *& rpAdd, bool bIsAarray)
{
	if (nullptr == rpAdd)
		return;

	if (bIsAarray)
		delete[] rpAdd;
	else
		delete rpAdd;
	rpAdd = nullptr;
}	


template<typename T>
bool CMergerSort<T>::Malloc(int iSize)
{
	m_piBuffer = new T[iSize]; 
	if (nullptr == m_piBuffer)
	{
		cout << "CMergerSort::Malloc() __ fail" << endl;
		return true;
	}
	
	return false;
}

template<typename T>
void CMergerSort<T>::Release()
{
	Safe_Delete(m_piBuffer);
}


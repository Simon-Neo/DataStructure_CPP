#include "stdafx.h"
#include "Set.h"


CSet::CSet()
{
}

CSet::CSet(int iMax)
{
	if (Initialize(iMax) == false)
	{
		cout << "Initialize Fail" << endl;
		return;
	}
}

CSet::CSet(const CSet & rhs)
{
	cout << "CSet::CSet(const CSet & rhs)" << endl;
	Release();
	Initialize(rhs.m_iMax);
	m_iMax = rhs.m_iMax;
	m_iIndex = rhs.m_iIndex;

	memcpy(m_pArrSet, rhs.m_pArrSet, sizeof(int) * rhs.m_iIndex);
}

CSet::CSet(CSet && rrhs)
{
	cout << "CSet::CSet(CSet && rrhs)" << endl;

	m_pArrSet = rrhs.m_pArrSet;
	m_iIndex = rrhs.m_iIndex;
	m_iMax = rrhs.m_iMax;

	rrhs.m_pArrSet = nullptr;
	rrhs.m_iIndex = 0;
	rrhs.m_iMax = 0;
}

CSet::~CSet()
{
	Release();
}

int CSet::Initialize(int iMax)
{
	Release();
	m_iMax = iMax;
	m_pArrSet = new int[m_iMax];
	if (IsSetArrayNull())
		return 0;

	memset(m_pArrSet, 0, sizeof(int) * m_iMax);
	return 1;
}

int CSet::IsMember(int iData) const 
{
	if (IsSetArrayNull())
		return 0;

	return BinarySearch(m_pArrSet, 0, m_iIndex - 1, iData);

	//(m_iIndex - 1) / 2;

	//for (int i = 0; i < m_iIndex; ++i)
	//	if (iData == m_pArrSet[i])
	//		return i;

	//return -1;
}

void CSet::Add(int iData)
{
	if (IsSetArrayNull())
		return;

	if (m_iIndex != 0)
	{
		if (IsFull() || IsMember(iData) != -1) // ★★
			return;
	}

	m_pArrSet[m_iIndex++] = iData;

	// Quick Sort
	QuickSort(m_pArrSet, 0, m_iIndex - 1);
}

void CSet::Remove(int iData)
{
	if (IsSetArrayNull())
		return ;

	int iCheckIndex = 0;
	if ((iCheckIndex = IsMember(iData)) != -1)// ★★★★★★★★ 아놔 .. 이똑똒이..ㅋ
		m_pArrSet[iCheckIndex] = m_pArrSet[--m_iIndex];

	// Quick Sort
	QuickSort(m_pArrSet, 0, m_iIndex - 1);

}


bool CSet::IsEmpthy() const
{
	if (1 > m_iIndex )
	{
		cout << "Is Emmpthy Set" << endl;
		return true;
	}

	return false;
}

bool CSet::IsFull()const
{
	if (m_iMax <= m_iIndex)
	{
		cout << "Is Full Set" << endl;
		return true;
	}
	
	return false;
}

bool CSet::IsSetArrayNull() const
{
	if (nullptr == m_pArrSet)
	{
		cout << "nullptr == m_pArrSet" << endl;
		return true;
	}
	return false;
}

int CSet::Capacity() const
{
	if (IsSetArrayNull())
		return 0;
	
	return m_iMax;;
}

int CSet::Size() const
{
	if (IsSetArrayNull())
		return 0;

	return m_iIndex;;
}

void CSet::Assign(const CSet & rSet)
{
	int iSize = rSet.Size();
	if (rSet.Size() > m_iMax) 
	{
		// input Array bigger then me
		Release();
		Initialize(iSize);
	}
	
	m_iIndex = iSize;
	for (int i = 0; i < iSize; ++i)
		m_pArrSet[i] = rSet.m_pArrSet[i];

	// Quick Sort
	QuickSort(m_pArrSet, 0, m_iIndex - 1);
}

int CSet::Equal(const CSet & rSet)
{
	if (m_iIndex != rSet.m_iIndex)
		return 0;

	for (int i = 0; i < m_iIndex; ++i)
		if (m_pArrSet[i] != rSet.m_pArrSet[i])
			return 0;

	//int j = 0;
	//for (int i = 0; i < m_iIndex; ++i)
	//{
	//	for (j = 0; j < rSet.m_iIndex; ++j)
	//		if (m_pArrSet[i] == rSet.m_pArrSet[j]) // same _> break
	//			break;
	//	if (j >= rSet.m_iIndex)
	//		return  0;
	//}
	return 1;
}

CSet CSet::Union(const CSet & rSet)
{
	CSet cOnly_B = rSet - *this;

	CSet cResult = CSet(cOnly_B.m_iIndex + m_iIndex);
	cResult.Assign(*this);

	for (int i = 0; i < cOnly_B.m_iIndex; ++i)
		cResult.Add(cOnly_B.m_pArrSet[i]);

	return cResult;
}

CSet CSet::Intersection(const CSet & rSet)
{
	int iNewMax = 0;

	CSet cNewSet = CSet(m_iMax);

	for (int i = 0; i < m_iIndex; ++i)
	{
		for (int j = 0; j < rSet.m_iIndex; ++j)
		{
			if (m_pArrSet[i] == rSet.m_pArrSet[j])
			{
				cNewSet.Add(m_pArrSet[i]);
			}
		}
	}
	return cNewSet;
}

CSet CSet::operator-(const CSet & rSet) const
{
	CSet cNewSet = CSet(m_iIndex);

	int j = 0;
	for (int i = 0; i < m_iIndex; ++i)
	{
		for (j = 0; j < rSet.Size() && m_pArrSet[i] != rSet.m_pArrSet[j]; ++j)
		{
		}
		if (rSet.m_iIndex <= j)
			cNewSet.Add(m_pArrSet[i]);
	}

	return cNewSet;
}

CSet& CSet::operator=(CSet && rrhs)
{
	cout << "CSet CSet::operator=(CSet && rrhs)" << endl;
	
	Release();
	m_pArrSet = rrhs.m_pArrSet;
	m_iIndex = rrhs.m_iIndex;
	m_iMax = rrhs.m_iMax;

	rrhs.m_pArrSet = nullptr;
	rrhs.m_iIndex = 0;
	rrhs.m_iMax = 0;
	return *this;
}


void CSet::Print()
{
	if (IsEmpthy())
		return;

	cout << "{";
	for (int i = 0; i < m_iIndex - 1; ++i)
	{
		cout << m_pArrSet[i] << " ";
	}
	cout << m_pArrSet[m_iIndex - 1] << "}" << endl;
}

void CSet::Release()
{
	Safe_Delete(m_pArrSet, true);
	m_iMax = 0;
	m_iIndex = 0;
}

int CSet::BinarySearch(int iArray[], int iL, int iR, int iInput) const
{
	if (iL >= iR)
		return iInput == iArray[iL] ? iL : -1;


	int iMid = (iR + iL) / 2;

	if (iArray[iMid] == iInput)
		return iMid;
	else if (iArray[iMid] > iInput)
		return BinarySearch(iArray, iL, iMid - 1, iInput);
	else
		return BinarySearch(iArray, iMid + 1, iR, iInput);
}

CSet CSet::symmetricDifference(const CSet & rSet)
{
	CSet&& rrDiffer_A = (*this) - rSet;
	CSet&& rrDiffer_B = rSet - (*this);

	CSet cNew = rrDiffer_A.Union(rrDiffer_B);
	return cNew;
}

CSet * CSet::ToUnion(const CSet & rSet)
{
	// ★★ 간단하게 해결해버리시네.. 너무 내가엉렵ㄱ ㅔ생각해버림.
	for (int i = 0; i < rSet.m_iIndex; ++i)
		Add(rSet.m_pArrSet[i]);

	return this;
}

CSet * CSet::ToIntersection(const CSet & rSet)
{
	for (int i = 0; i < m_iIndex; ++i)
	{
		if (-1 == rSet.IsMember(m_pArrSet[i]))
			// No Is Memeber A Value in B Array
			m_pArrSet[i--] = m_pArrSet[--m_iIndex];
	}

	// Quick Sort
	QuickSort(m_pArrSet, 0, m_iIndex - 1);

	return this;
}

CSet * CSet::ToDifference(const CSet & rSet)
{
	// ★★ 아놔 ...

	for (int i = 0; i < rSet.m_iIndex; ++i)
	{
		Remove(rSet.m_pArrSet[i]);
	}

	//for (int i = 0; i < m_iIndex; ++i)
	//{
	//	if (-1 != rSet.IsMember(m_pArrSet[i]))
	//	{
	//		m_pArrSet[i--] = m_pArrSet[--m_iIndex];
	//	}
	//}
	return this;
}

int CSet::IsSubset(const CSet & rSet)
{
	int j = 0;
	for (int i = 0; i < m_iIndex; ++i)
	{
		if (rSet.IsMember(m_pArrSet[i]) == -1)
			return 0;
	}
	return 1;
}

int CSet::IsProperSubset(const CSet & rSet)
{
	if (m_iIndex == rSet.m_iIndex)
		return 0;
	
	return IsSubset(rSet);
}

void CSet::QuickSort(int iArray[], int iL, int iR)
{
	if (nullptr == iArray)
		return;

	if (iL >= iR)
		return;

	int iB_L = iL;
	int iB_R = iR;

	int iMid = (iR + iL) / 2;
	int iMIdVal = iArray[iMid];

	while (iL <= iR)
	{
		while (iArray[iL] < iMIdVal) ++iL;
		while (iArray[iR] > iMIdVal) --iR;

		if(iL <= iR)
			Swap(iArray[iL++], iArray[iR--]);
	}
	
	QuickSort(iArray, iB_L, iR);
	QuickSort(iArray, iL, iB_R);
}


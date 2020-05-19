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

int CSet::IsMember(int iData)
{
	if (IsSetArrayNull())
		return 0;

	for (int i = 0; i < m_iIndex; ++i)
		if (iData == m_pArrSet[i])
			return i;

	return -1;
}

void CSet::Add(int iData)
{
	if (IsSetArrayNull())
		return ;

	if (IsFull() || IsMember(iData) != -1) // ¡Ú¡Ú
		return;

	m_pArrSet[m_iIndex++] = iData;
}

void CSet::Remove(int iData)
{
	if (IsSetArrayNull())
		return ;

	int iCheckIndex = 0;
	if ((iCheckIndex = IsMember(iData)) != -1)// ¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú ¾Æ³ö .. ÀÌ¶ÈŒQÀÌ..¤»
		m_pArrSet[iCheckIndex] = m_pArrSet[--m_iIndex];
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
	Release();
	Initialize(rSet.Capacity());
	m_iIndex = rSet.Size();
	for (int i = 0; i < m_iIndex; ++i)
		m_pArrSet[i] = rSet.m_pArrSet[i];
}

int CSet::Equal(const CSet & rSet)
{
	if (m_iIndex != rSet.m_iIndex)
		return 0;

	for (int i = 0; i < m_iIndex; ++i)
	{
		if (m_pArrSet[i] != rSet.m_pArrSet[i])
			return 0;
	}
	return 1;
}

CSet CSet::Union(const CSet & rSet)
{
	int iMax = m_iIndex;
	CSet* cTemp = new CSet(rSet.Size());

	int iSameVal = -1;
	for (int i = 0; i < rSet.m_iIndex; ++i)
	{
		for (int j = 0; j < m_iIndex; ++j)
		{
			if (rSet.m_pArrSet[i] == m_pArrSet[j])
			{
				iSameVal = -1;
				break;
			}
			iSameVal = rSet.m_pArrSet[i];
		}
		if (-1 != iSameVal)
		{
			++iMax;
			cTemp->Add(iSameVal);
		}
	}

	CSet cSet(iMax);
	for (int i = 0; i < m_iIndex; ++i)
	{
		cSet.Add(m_pArrSet[i]);
	}

	for (int i = 0; i < cTemp->Size(); ++i)
	{
		cSet.Add(cTemp->m_pArrSet[i]);
	}

	Safe_Delete(cTemp);
	return cSet;
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

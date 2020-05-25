#include "stdafx.h"
#include "BitSet.h"


CBitSet::CBitSet()
{
}


CBitSet::~CBitSet()
{
}

int CBitSet::operator==(const CBitSet & rhs) const
{
	return 	m_bitSet == rhs.m_bitSet;
}
int CBitSet::operator!=(const CBitSet & rhs) const
{
	return 	m_bitSet != rhs.m_bitSet;
}

inline BITSET CBitSet::SetOf(int iNum) const
{
	BITSET bitDest = 0x01;
	bitDest = bitDest << iNum;
	return BITSET(bitDest);
}

int CBitSet::IsMember(int iData)
{
	return m_bitSet & SetOf(iData);
}

int CBitSet::IsMember(BITSET bitset, int iData) const
{
	return bitset & SetOf(iData);
}

void CBitSet::Add(int iData)
{
	m_bitSet |= SetOf(iData);
}

void CBitSet::Remove(int iData)
{
	m_bitSet &= ~SetOf(iData);
}

int CBitSet::Size()
{
	BITSET bitTemp = m_bitSet;
	int iSize = 0;
	for (; bitTemp != BITSET_NULL; ++iSize)
		bitTemp &= bitTemp - 1;
	// 개똑똑쓰... ㅎ 역쉬 

	return iSize;
}

void CBitSet::Print()
{
	int iTemp = 0;
	cout << "{ ";
	for (int i = 0; i < BITSET_MAX; ++i)
	{
		iTemp = IsMember(i);
		if (iTemp)
			cout << i << " ";
	}
	cout << "}" << endl;
		
}

void CBitSet::Print(BITSET bitSet) const
{
	int iTemp = 0;
	cout << "{ ";
	for (int i = 0; i < BITSET_MAX; ++i)
	{
		iTemp = IsMember(bitSet,i);
		if (iTemp)
			cout << i << " ";
	}
	cout << "}" << endl;

}

BITSET CBitSet::Intersection(const CBitSet & rhs) const
{
	BITSET bitSet(m_bitSet & rhs.m_bitSet);
	cout << "intersection --------------" << endl;
	Print(bitSet);
	return bitSet;
}

BITSET CBitSet::Union(const CBitSet & rhs) const
{
	BITSET bitSet(m_bitSet | rhs.m_bitSet);
	cout << "Uinon --------------" << endl;
	Print(bitSet);
	return bitSet;
}

BITSET CBitSet::Difference(const CBitSet & rhs) const
{
	BITSET bitSet(m_bitSet & (~rhs.m_bitSet));
	cout << "Difference --------------" << endl;
	Print(bitSet);
	return bitSet;
}

BITSET CBitSet::SymmetricDifference(const CBitSet & rhs) const
{
	BITSET bitSet(m_bitSet ^ rhs.m_bitSet);
	cout << "Symmetric Difference --------------" << endl;
	Print(bitSet);
	return bitSet;
}





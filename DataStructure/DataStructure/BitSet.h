#pragma once


#define BITSET_NULL (BITSET)0
#define BITSET_MAX 32

class CBitSet
{
public:
	CBitSet();
	~CBitSet();
public:
	int operator==(const CBitSet& rhs)const;
	int operator!=(const CBitSet& rhs)const;

public:
	inline BITSET SetOf(int iNum) const;

	int IsMember(int iData);
	int IsMember(BITSET bitset,int iData) const;

	void Add(int iData);
	void Remove(int iData);
	int Size();
	
	void Print();

	void Print(BITSET bitSet)const;

	// SET
	BITSET Intersection(const CBitSet& rhs)const;
	BITSET Union(const CBitSet& rhs)const;
	BITSET Difference(const CBitSet& rhs)const;
	BITSET SymmetricDifference(const CBitSet& rhs)const;
private:

private:
	BITSET m_bitSet = 0;
};


#pragma once


class CSet
{
public:
	CSet();
	explicit CSet(int iMax);
	CSet(const CSet& rhs);
	CSet(CSet&& rrhs);
	~CSet();
public:
	int Initialize(int iMax);
	int IsMember(int iData) const;
	void Add(int iData);
	void Remove(int iData);

	bool IsEmpthy()const;
	bool IsFull()const;
	bool IsSetArrayNull() const;

	int Capacity() const ;
	int Size() const;

	void Assign(const CSet& rSet);
	int Equal(const CSet& rSet);
	CSet Union(const CSet& rSet);
	CSet Intersection(const CSet& rSet);
	CSet operator -(const CSet& rSet) const;

	void Print();

	void Release();


	// --- Practice Question 
	void Clear() { m_iIndex = 0; };

	CSet symmetricDifference(const CSet& rSet);
	CSet* ToUnion(const CSet& rSet);
	CSet* ToIntersection(const CSet& rSet);
	CSet* ToDifference(const CSet& rSet);

	int IsSubset(const CSet& rSet);
	int IsProperSubset(const CSet& rSet);

private:
	int m_iMax = 0;
	int m_iIndex = 0;
	int* m_pArrSet = nullptr;
};
#pragma once



class CDegreeSort
{
public:
	CDegreeSort(int pArray[], int);
	~CDegreeSort();

public:
	void Sort(int pArray[], int iSize);
private:
	void Release();
	void Max(const int pArray[], int);
	void Min(const int pArray[], int);


private:
	int* m_pCumulateArray = nullptr;
	int* m_pArrangeArray = nullptr;
	int m_iMax = 0;
	int m_iMin = 0;
	int m_iHeapSize = 0;
};


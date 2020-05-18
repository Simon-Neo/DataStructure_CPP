#pragma once

template<typename T>
class CMergerSort
{
public:
	CMergerSort();
	~CMergerSort();

public:
	//void MergerSort(int* piArray, int iSize);

	//void Merger(int* piArray, int iL, int iR);

	void merger(T * pArray, int iL, int iR,
		int(*compare)(const T&, const T&));

	void m_sort(T* pArray, size_t iSize,
		int(*compare)(const T&, const T&));

private:
	bool Malloc(int iSize);

	void Release();

	void Safe_Delete(T*& rpAdd, bool bIsAarray = false);
private:
	T* m_piBuffer = nullptr;
};


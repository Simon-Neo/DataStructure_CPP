#pragma once


//#define HEAP_RECUR

class CHeapSort
{
public:
	CHeapSort();
	~CHeapSort();
public:
	void Render(int* piArray, int iSize);
#ifdef HEAP_RECUR
	void Heap(int* piArray, int iSize, int iNowIndex);
	void DownHeap(int* piArray, int iSize, int iNowIndex);
	void ArrangeHeap(int* piArray, int iSize);
#else
	void HEAP(int piArray[], int iSize);
	void DOWN_HEAP(int piArray[], int iStart, int iEnd);
#endif // HEAP_RECUR


private:
	int Pow2(int iSquare);
};


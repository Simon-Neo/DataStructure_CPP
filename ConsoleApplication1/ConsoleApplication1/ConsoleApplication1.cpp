// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

/*--- 2의 n 제곱을 구합니다. ---*/
static int pow2(int n)
{
	int k = 1;

	while (n--)
		k *= 2;
	return (k);
}


/*--- 힙 출력 ---*/
static void disp_heap(int a[], int n)
{
	int i, w, level;
	int height = 1;		/* 트리의 높이 */

	i = n;
	while (i /= 2)
		height++;

	i = 0;
	w = 1;

	for (int ZZ = 0; ZZ < 50; ++ZZ)
	{
		printf("%2d", ZZ);
	}
	printf("\n");
	for (level = 0; level < height; level++) {
		int k;
		printf("%*s", pow2(height - level) - 2, "");
		for (k = 0; k < w; k++)
		{
			printf("%02d", a[i++]);
			if (i >= n) goto Exit;
			printf("%*s", pow2(height - level + 1) - 2, "");
		}
		putchar('\n');

		printf("%*s", pow2(height - level) - 3, "");

		for (k = 0; k < w; k++)
		{
			if (2 * k + i     < n) printf("／");
			if (2 * k + i + 1 < n) printf("＼");
			printf("%*s", pow2(height - level + 1) - 4, "");
		}
		putchar('\n');
		w *= 2;
	}
Exit:
	putchar('\n');
	putchar('\n');
}

template<typename T>
static inline void Swap(T & rA, T & rB)
{
	T tTemp = rA;
	rA = rB;
	rB = tTemp;
}

void downheap(int a[], int iL, int iR)
{
	int temp = a[iL];
	int child;
	int parent;

	for (parent = iL; parent < (iR + 1) / 2; parent = child)
	{
		int cL = parent * 2 + 1;
		int cR = cL + 1;
		child = (cR <= iR && a[cR] > a[cL]) ? cR : cL;

		if (temp >= a[child])
			break;
		a[parent] = temp;
	}
}

void heapsort(int a[], int iSize)
{
	int i;
	for (i = (iSize - 1) / 2; i >= 0; i--)
		downheap(a, i, iSize - 1);

	for (i = iSize - 1; i > 0; i--)
	{
		Swap(a[i], a[iSize - 1]);
		downheap(a, 0, i - 1);
	}

}



int main()
{
	const int iSize = 10;
	int iArray[iSize] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	heapsort(iArray, iSize);

	
	
    return 0;
}


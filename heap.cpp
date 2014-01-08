#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static void exchage_value(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
void heap_modify(int a[], int loc)
{

	int largest = loc;
	if (2*loc <= a[0] && a[2*loc] > a[largest])
	{
		largest = 2*loc;

	}
	if ((2*loc+1) <= a[0] && a[2*loc+1] > a[largest])
	{
		largest = 2*loc+1;
	}
	if (largest != loc)
	{
		exchage_value(a, largest, loc);
		heap_modify(a, largest);
	}
	return;
}

int* heap_build(int b[], int n)
{
	int* p = (int*)malloc(sizeof(int)*(n+1));

	if (NULL != p)
	{
		p[0] = n;
		printf("count: %d\n", p[0]);
		memcpy(p+1, b, n*sizeof(int));
		for (int i = n/2; i >= 1; i--)
		{
			heap_modify(p, i);
		}
	}
	return p;
}

int main()
{
	int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int* b = heap_build(a, sizeof(a)/sizeof(a[0]));
	if (NULL != b)
	{
		for (int i = 1; i <= 10; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}

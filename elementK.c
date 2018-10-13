#include <stdio.h>
#include <limits.h>
void main(){
	int a[] = { 3, 10, 59, 32, 116, 1, 2, 10, 10, 10 };
	int elementK = 0;
	// max = so lon nhat
    //maxK = so nho nhat
	int max = INT_MAX, maxK = INT_MIN;
	// input element lon thu K can tim
	printf("Input: \n");
	scanf_s("%d", &elementK);
	for (int i = 0; i < elementK; i++)
	{
		//Gan maxK = so nho nhat
		maxK = INT_MIN;
		for (int j = 0; j < 10; j++)
		{
			if (a[j] > maxK && a[j] < max)
				maxK = a[j];
		}
		max = maxK;
	}
	printf("Max element %d is %d", elementK, max);
}

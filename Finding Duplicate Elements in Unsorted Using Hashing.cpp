//Finding Duplicate Elements in Unsorted Array in Hashing

#include <stdio.h>
#include <stdlib.h>
struct Array{
	int *A;
	int size;
	int length;
};
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
int Max(struct Array arr)
{
	int max=arr.A[0];
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]>max)
			max=arr.A[i];
	}
	return max;
}
void DuplicateUnsortedHashing(struct Array arr)
{
	struct Array H;
	H.A=(int *)malloc(Max(arr)*sizeof(int));
	int high=Max(arr);
	for(int i=0;i<high;i++)
	{
		H.A[i]=0;
	}
	for(int i=0;i<arr.length;i++)
	{
		H.A[arr.A[i]]++;
	}
	for(int i=0;i<=high;i++)
	{
		if(H.A[i]>1)
			printf("\n%d is appearing %d times\n",i,H.A[i]);
	}
}
int main()
{
	struct Array arr;
	printf("Enter the size of array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));
	int n;
	printf("Enter how many elements: ");
	scanf("%d",&n);
	printf("Enter the unsorted elements:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	arr.length=n;
	Display(arr);
	DuplicateUnsortedHashing(arr);
	return 0;
}

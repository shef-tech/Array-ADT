//Finding missing element in unsorted Array using Hashing

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
	{
		printf("%d  ",arr.A[i]);
	}
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
int Min(struct Array arr)
{
	int min=arr.A[0];
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]<min)
		 min=arr.A[i];
	}
	return min;
}
void MultipleMissingUnsorted(struct Array arr)
{
	struct Array H;
	int high=Max(arr);
	H.A=(int *)malloc(high*sizeof(int));
	for(int i=0;i<high;i++) //Putting every value as 0
	{
		H.A[i]=0;
	}
	for(int i=0;i<arr.length;i++)
	{
		H.A[arr.A[i]]++;
	}
	printf("\n\nThe missing elements are:\n");
	for(int i=Min(arr);i<=Max(arr);i++)
	{
		if(H.A[i]==0)
			printf("%d ",i);
	}
}
int main()
{
	struct Array arr;
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));
	
	printf("Enter how many numbers: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	arr.length=n;
	
	Display(arr);
	MultipleMissingUnsorted(arr);
	
	return 0;
}

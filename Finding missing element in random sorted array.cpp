//Finding single missing element in random sorted array

#include <iostream>
#include <stdlib.h>
using namespace std;
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

void SingleMissingRan(struct Array arr)
{
	int l=arr.A[0];
	int diff=l-0;
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]-i!=diff)
		{
			printf("\nMissing Element is %d",i+diff);
			break;
		}
	}
}
int main()
{
	struct Array arr;
	printf("Enter the size of the array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(sizeof(int)*arr.size);
	arr.length=0;
	
	int n;
	printf("Enter how many number?\n");
	scanf("%d",&n);
	printf("Enter the elements in sorted order:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	arr.length=n;
	Display(arr);
	SingleMissingRan(arr);
	return 0;
}

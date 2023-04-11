//Finding Missing Element in Sorted Array starting from 1 

#include <stdio.h>
struct Array{
	int A[15];
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
void SingleMissing(struct Array arr)
{
	int sum=0;
	int n=arr.length;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr.A[i];
	}
	int s=n*(n+1)/2;
	printf("\nMissing number is %d",sum-s);
}
int main()
{
	struct Array arr1={{1,2,4,5,6},10,5};
	Display(arr1);
	SingleMissing(arr1);
	printf("\n");
	return 0;
}

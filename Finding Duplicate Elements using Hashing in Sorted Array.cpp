//Finding Duplicate ELements using Hashing in Sorted Array

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
void FindDuplicateHash(struct Array arr)
{
	struct Array H;
	int l,h;
	l=arr.A[0];
	h=arr.A[arr.length-1];
	H.A=(int *)malloc(h*sizeof(int));
	for(int i=0;i<h;i++)
	{
		H.A[i]=0;
	}
	for(int i=0;i<arr.length;i++)
		H.A[arr.A[i]]++;
	for(int i=1;i<=h;i++)
	{
		if(H.A[i]>1)
			printf("\n%d is present is %d times\n",i,H.A[i]);
	}
}
int main()
{
	struct Array arr;
	int n;
	printf("Enter the size of the Array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));
	printf("Enter how many elements: ");
	scanf("%d",&n);
	
	printf("Enter the elements in sorted order:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	arr.length=n;
	Display(arr);
	FindDuplicateHash(arr);
	return 0;
}

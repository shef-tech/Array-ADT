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
void PairSumHashing(struct Array arr,int k)
{
	struct Array H;
	int high=Max(arr);
	H.A=(int *)malloc(high*sizeof(int));
	for(int i=0;i<high;i++)
	{
		H.A[i]=0;
	}
	for(int i=0;i<arr.length;i++)
	{
		if(H.A[k-arr.A[i]] != 0)
			printf("\n%d + %d = %d\n",arr.A[i],k-arr.A[i],k);
		H.A[arr.A[i]]++;
	}
}
int main()
{
	struct Array arr;
	printf("Enter the size of the array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(sizeof(int)*arr.size);
	int n;
	printf("Enter how many elements: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	arr.length=n;
	Display(arr);
	PairSumHashing(arr,10);
	return 0;
}

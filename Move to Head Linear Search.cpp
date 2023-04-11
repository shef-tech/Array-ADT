//Move to Head in Linear Search
#include <stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int MovToHeadLinearSearch(struct Array *arr,int x)
{
	for(int i=0;i<arr->length;i++)
	{
		if(arr->A[i]==x)
		{
			swap(&arr->A[i],&arr->A[0]);
			return 0;
		}
	}
	return -1;
}
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
int main()
{
	struct Array arr={{2,4,6,8,9},10,5};
	printf("Before: ");
	Display(arr);
	int n=MovToHeadLinearSearch(&arr,8);
	if(n==-1)
		printf("\nElement not Found\n");
	else
	{
		printf("\nAfter Transposition Linear Search:\n");
		Display(arr);
		printf("\nElement is found in index %d",n);
	}
}

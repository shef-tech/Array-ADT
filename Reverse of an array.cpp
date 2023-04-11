//Reverse of an Array

#include <stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
void Display(struct Array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
void Swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

//Reversing by using auxillary array B
void Reverse(struct Array *arr)
{
	int *B;
	int i,j;
	for(i=arr->length-1,j=0;i>=0;i--,j++)
		B[j]=arr->A[i];
	for(i=0,j=0;i<arr->length;i++,j++)
		arr->A[i]=B[j];
}

//Reversing using swap
void Reverse2(struct Array *arr)
{
	int i,j;
	for(i=0,j=arr->length-1;i<j;i++,j--)
		Swap(&arr->A[i],&arr->A[j]);
}
int main()
{
	struct Array arr={{2,4,5,6,8,9},10,6};
	struct Array arr2={{7,8,3,9,10,11},10,6};
	printf("Before Reversing array 1:\n");
	Display(arr);
	Reverse(&arr);
	printf("\nAfter Reversing 1st way:\n");
	Display(arr);
	printf("\nBefore Reversing array 2:\n");
	Display(arr2);
	Reverse2(&arr2);
	printf("\nAfter Reversing 2nd way:\n");
	Display(arr2);
	return 0;
}

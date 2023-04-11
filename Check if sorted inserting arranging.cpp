//Check if the Array is Sorted
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
void InsertSort(struct Array *arr,int x)
{
	int i=arr->length-1;
	if(arr->length<arr->size)
	{
		while(arr->A[i]>x)
		{
			arr->A[i+1]=arr->A[i];
			i--;
		}
		arr->A[i+1]=x;
		arr->length++;
	}
}
int isSorted(struct Array arr)
{
	int i;
	for(i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]>arr.A[i+1])
			return 1;
	}
	return 0;
}
void Swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int Rearrange(struct Array *arr)
{
	int i=0,j=arr->length-1;
	while(i<j)
	{
		while(arr->A[i]<0) i++;
		while(arr->A[j]>0) j--;
		if(i<j)
			Swap(&arr->A[i],&arr->A[j]);
	}
}
int main()
{
	struct Array arr={{2,4,6,7,9},10,5};
	struct Array arr2={{2,-4,6,7,-9,3,-1,5},10,8};
	Display(arr);
	InsertSort(&arr,5);
	printf("\nAfter Inserting an element:\n");
	Display(arr);
	int n=isSorted(arr);
	if(n==0)
		printf("\nArray is Sorted\n");
	else
		printf("\nArray is not Sorted\n");
	printf("Before rearranging second Array:\n");
	Display(arr2);
	Rearrange(&arr2);	
	printf("\nAfter rearranging:\n");
	Display(arr2);	
}

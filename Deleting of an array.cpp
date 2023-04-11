//Deleting of an array

#include<stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
int Delete(struct Array *arr,int index)
{
	int x=0;
	int i;
	if(index>=0 && index<arr->length)
	{
		x=arr->A[index];
		for(i=index;i<arr->length-1;i++)
			arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;	
	}
}
void Display(struct Array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
int main()
{
	struct Array arr={{2,4,6,8,10},10,5};
	printf("Before:\n");
	Display(arr);
	printf("\nDeleted value is: %d",Delete(&arr,3));
	printf("\nAfter Deleting\n");
	Display(arr);
}


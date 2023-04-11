//Get Set Avg Max

#include <stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
void Display(struct Array arr)
{
	int i;
	printf("The elements in the array are:\n");
	for(i=0;i<arr.length;i++)
	{
		printf("%d  ",arr.A[i]);
	}
}
int Get(struct Array arr,int index)
{
	if(index>=0 && index<arr.length)
		return arr.A[index];
	return -1;
}
int Set(struct Array *arr,int index,int x)
{
	if(index>=0 && index<arr->length)
		arr->A[index]=x;
	return -1;
}
int Max(struct Array arr)
{
	int max=arr.A[0];
	for(int i=1;i<arr.length;i++)
	{
		if(arr.A[i]>max)
			max=arr.A[i];
	}
	return max;
}
int Min(struct Array arr)
{
	int i;
	int min=arr.A[0];
	for(i=1;i<arr.length;i++)
	{
		if(arr.A[i]<min)
			min=arr.A[i];
	}
	return min;
}
int Sum(struct Array arr)
{
	int i;
	int sum=0;
	for(i=0;i<arr.length;i++)
	{
		sum+=arr.A[i];
	}
	return sum;
}
float Avg(struct Array arr)
{
	return (float)Sum(arr)/arr.length;
}
int main()
{
	struct Array arr={{2,5,6,8,9},10,5};
	Display(arr);
	int n=Get(arr,9);
	if(n==-1)
		printf("\nIndex out of range\n");
	else 
	{
		printf("\nUsing Get function: %d\n",Get(arr,3));
	}
	printf("\nAfter using Set function:\n",Set(&arr,2,25));
	Display(arr);
	printf("\nThe max element in the array: %d\n",Max(arr));
	printf("\nThe min element in the array: %d\n",Min(arr));
	printf("\nSum of the elements: %d\n",Sum(arr));
	printf("\nThe average of the elements: %.2f\n",Avg(arr));
}

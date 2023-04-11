//Array ADT using Dynamic Variable

#include <stdio.h>
#include <stdlib.h>
struct Array{
	int *A;
	int size;
	int length;
};
void Display(struct Array arr){
	int i;
	printf("The length of the array is %d\n",arr.length);
	for(i=0;i<arr.length;i++)
	{
		printf("%d    ",arr.A[i]);
	}
}
int main()
{
	struct Array arr;
	printf("Enter the size of the array: ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));
	arr.length=0;

	int n;
	printf("Enter how many numbers: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr.A[i]);
	}
	arr.length=n;
	Display(arr);
	return 0;
}


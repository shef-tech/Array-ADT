//Finding and counting the duplicates in sorted array

#include <stdio.h>
struct Array{
	int A[15];
	int size;
	int length;
};
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
void FindDuplicate(struct Array arr)
{
	int lastDuplicate=0;
	printf("\nThe duplicate numbers are:\n");
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]==arr.A[i+1] && arr.A[i]!=lastDuplicate)
		{
			printf("%d  ",arr.A[i]);
			lastDuplicate=arr.A[i];
		}
	}
}
void CountingDuplicate(struct Array arr)
{
	int j;
	for(int i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]==arr.A[i+1])
		{
			j=i+1;
			while(arr.A[j]==arr.A[i])
			{
				j++;
			}
			printf("\nMissing element %d is appearing %d times\n",arr.A[i],j-i);
			i=j-1;
		}
	}
}
int main()
{
	struct Array arr={{3,6,8,8,10,12,15,15,15,20},15,10};
	Display(arr);
	FindDuplicate(arr);
	CountingDuplicate(arr);
	return 0;
}

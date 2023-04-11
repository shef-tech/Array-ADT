//Finding Duplicate Elements in unsorted Array

#include <stdio.h>
struct Array{
	int A[20];
	int size;
	int length;
};

void DuplicateUnsorted(struct Array arr)
{
	for(int i=0;i<arr.length-1;i++)
	{
		int count=1;
		if(arr.A[i]!=-1)
		{
			for(int j=i+1;j<arr.length;j++)
			{
				if(arr.A[i]==arr.A[j])
				{
					count++;
					arr.A[j]=-1;
				}
			}
			if(count>1)
				printf("\n%d is appearing %d times\n",arr.A[i],count);
		}
	}
}
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
	{
		printf("%d  ",arr.A[i]);
	}
}
int main()
{
	struct Array arr={{8,3,6,4,6,5,6,8,2,7},15,10};
	Display(arr);
	DuplicateUnsorted(arr);
	return 0;
}

//Finding Multiple Missing ELements in sorted Array 

#include <stdio.h>
struct Array{
	int A[15];
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
void MultipleMissing(struct Array arr)
{
	int l=arr.A[0];
	int diff=l-0;
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]-i!=diff)
		{
			printf("\nMissing Elements are:\n");
			while(diff<arr.A[i]-i)
			{
				printf("%d  ",i+diff);
				diff++;
			}
		}
	}
}
int main()
{
	struct Array arr={{6,7,8,9,11,12,15,16,17,18,19},15,11};
	Display(arr);
	MultipleMissing(arr);
	return 0;
}

//Finding a pair with sum k in unsorted Array

#include <stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
void PairSum(struct Array arr,int k)
{
	printf("\n\nPair that makes %d",k);
	for(int i=0;i<arr.length-1;i++)
	{
		for(int j=i+1;j<arr.length;j++)
		{
			if(arr.A[i]+arr.A[j]==k)
				printf("\n%d + %d = %d\n",arr.A[i],arr.A[j],k);
		}
	}
}
int main()
{
	struct Array arr={{6,3,8,10,16,7,5,2,9,14},15,10};
	Display(arr);
	PairSum(arr,10);
	return 0;
}

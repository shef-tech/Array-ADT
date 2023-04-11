#include <stdio.h>
struct Array{
	int A[50];
	int size;
	int length;
};
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
		printf("%d  ",arr.A[i]);
}
void PairSumSorted(struct Array arr,int k)
{
	int i=0;
	int j=arr.length-1;
	while(i<j)
	{
		if(arr.A[i]+arr.A[j]==k)
		{
			printf("\n%d + %d = %d\n",arr.A[i],arr.A[j],k);
			i++;
			j--;
		}
		else if(arr.A[i]+arr.A[j]<k)
			i++;
		else
			j--;
	}
}
int main()
{
	struct Array arr={{1,3,4,5,6,8,9,10,12,14},15,10};
	Display(arr);
	PairSumSorted(arr,10);
	return 0;
}

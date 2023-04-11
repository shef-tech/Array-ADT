//Binary Search Recursion

#include <stdio.h>
struct Array{
	int A[10];
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
int RBinSearch(int A[],int l,int h,int key)
{
	int mid;
	if(l<=l)
	{
		mid=(l+h)/2;
		if(A[mid]==key)
			return mid;
		else if(key<A[mid])
			return RBinSearch(A,l,mid-1,key);
		else
			return RBinSearch(A,mid+1,h,key);
	}
	return -1;
}
int main()
{
	struct Array arr={{2,4,11,15,17,22,25,32,35},10,9};
	Display(arr);
	printf("\nThe element is present in index %d",RBinSearch(arr.A,0,arr.length,17));
}

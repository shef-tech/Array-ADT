//Binary Search Interation

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
int BinarySearch(struct Array arr,int key)
{
	int l=0;
	int h=arr.length-1;
	int mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key<arr.A[mid])
			h=mid-1;
		else 
			l=mid+1;
	}
	return -1;
}
int main()
{
	struct Array arr={{2,4,11,15,17,22,25,32,35},10,9};
	Display(arr);
	printf("\nThe element is present in index %d",BinarySearch(arr,17));
}

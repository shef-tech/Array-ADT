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
void MaxMin(struct Array arr)
{
	int min=arr.A[0];
	int max=arr.A[0];
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]>max)
			max=arr.A[i];
		else if(arr.A[i]<min)
			min=arr.A[i];
	}
	printf("\n\nMax number is %d\n",max);
	printf("\nMin number is %d\n",min);
}
int main()
{
	struct Array arr={{5,8,3,9,6,2,10,7,-1,4},15,10};
	Display(arr);
	MaxMin(arr);
	return 0;
}

//Array ADT static variable

#include <stdio.h>
struct Array{
	int A[10];
	int size;
	int length;
};
void Display(struct Array arr){
	int i;
	for(i=0;i<arr.length;i++)
	{
		printf("%d    ",arr.A[i]);
	}
}
int main()
{
	struct Array arr={{2,4,6,7,8},20,5};
	Display(arr);
	return 0;
}

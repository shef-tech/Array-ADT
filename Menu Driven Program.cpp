//Menu Driven Program

#include <stdio.h>
#include <stdlib.h>
struct Array{
	int *A;
	int size;
	int length;
};
void Insert(struct Array *arr,int index,int x)
{
	if(index>=0 && index<=arr->length)
	{
		for(int i=arr->length;i>index;i--)
		{
			arr->A[i]=arr->A[i-1];
		}
		arr->A[index]=x;
		arr->length++;
	}
}
int Delete(struct Array *arr,int index)
{
	int x=0;
	int i;
	if(index>=0 && index<arr->length)
	{
		x=arr->A[index];
		for(i=index;i<arr->length-1;i++)
			arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;	
	}
}
int LinearSearch(struct Array arr,int x)
{
	for(int i=0;i<arr.length;i++)
	{
		if(arr.A[i]==x)
			return i;
	}
	return -1;
}
void Display(struct Array arr)
{
	for(int i=0;i<arr.length;i++)
	{
		printf("%d  ",arr.A[i]);
	}
}
int Sum(struct Array arr)
{
	int i;
	int sum=0;
	for(i=0;i<arr.length;i++)
	{
		sum+=arr.A[i];
	}
	return sum;
}
int main()
{
	struct Array arr1;
	int ch;
	int x,index;
	printf("Enter the size of the array: ");
	scanf("%d",&arr1.size);
	arr1.A=(int *)malloc(arr1.size*sizeof(int));
	arr1.length=0;
	do{
	printf("Menu:\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Sum\n");
	printf("4. Display\n");
	printf("5. Search\n");
	printf("6. Exit\n");
	printf("\nEnter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the index and the element:\n");
			scanf("%d%d",&index,&x);
			Insert(&arr1,index,x);
			break;
		case 2:
			printf("Enter the index: ");
			scanf("%d",&index);
			Delete(&arr1,index);
			break;
		case 3:
			printf("The sum of the elements in the array is: %d",Sum(arr1));
			break;
		case 4:
			printf("The elements in the array are: ");
			Display(arr1);
			printf("\n");
			break;
		case 5:
			printf("Which elemet you want to search: ");
			scanf("%d",&x);
			printf("The element is present in %d",LinearSearch(arr1,x));
			break;
		default:
			printf("Program stopped\n");
	}
	}while(ch<6);
	return 0;
}

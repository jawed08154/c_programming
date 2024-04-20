#include<stdio.h>
#define MAX 10

int binary_serach(int *arr, int num)
{
	int start, end, mid;
	start = 0;
	end = MAX - 1;
	while(start <= end) {
		mid = (start + end) / 2;
		if (num == arr[mid])
			return mid;
		else if(num < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;	
	}
	return -1;
}

int main(int args, char **argv)
{

	int arr[MAX] = {2,4,13,18,32,45,68,72,78,88};
	int i,num, found;
	printf("Array contains elements are : \n");
	for(i = 0; i < MAX; i++)
		printf("%d  ", arr[i]);
	printf("\n Enter the element you want to find in the array\n");
	scanf("%d", &num);
	found = binary_serach(arr, num);
	if (found == -1)
		printf("sorry better luck next time !!! searched element is not part of the given array \n");
	else
		printf("yooo!!! found the element = %d at index %d\n", arr[found], found);
return 0;
}

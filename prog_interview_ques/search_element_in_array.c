#include <stdio.h>
#define MAX 10

int search_in_array(int [], int);

int main()
{
	int i, num, ret;
	int array[MAX] = {2,4,5,10,15,18,20,25,30,32};
	printf("sorted array : ");
	for (i = 0; i < MAX; i++)
		printf("%d ", array[i]);

	printf("\nEnter the element wanted to serach in sorted array: ");
	scanf("%d", &num);
	ret = search_in_array(array, num);
        
	if (ret >= 0 )
		printf("Element found in array at index = %d\n", ret);
	else
		printf("Element not found in the array\n");
return 0;
}


int search_in_array(int array[], int num)
{
	int i;
	int ret = -1;
	for (i = 0; i < MAX; i++) {
		if (array[i] == num)
		ret = i;	
	}	
        
	
return ret;
}

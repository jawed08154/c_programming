//Find count of an element in a sorted list
#include<stdio.h>
#define MAX 15

void show_array(int []);
int search_occurence_of_element_in_list(int [], int);
int bst_to_find_occurance_of_elemnt(int [], int);

int main()
{
	int arr[MAX] = {1,1,3,3,5,5,5,5,5,9,9,11};
	int num;
	int ret;
	show_array(arr); //print the sorted list
	printf("\nEnter the element to serach in sorted list ");
	scanf("%d", &num);
	//search the occurance of element in the list and return the no of occurance
	//with this time complexity is O(n)
	ret = search_occurence_of_element_in_list(arr, num);
        if (ret)
		printf("element found in the list and it occured %d times\n", ret);
	else
		printf("element not found in the list\n");

	//will try with binary search as array is sorted
	ret = bst_to_find_occurance_of_elemnt(arr, num);
        if (ret)
		printf("BST: element found in the list and it occured %d times\n", ret);
	else
		printf("BST: element not found in the list\n");
#if 0
        if (ret == -1)
		printf("element not found in the list\n");
	else
		printf("element found in the list at position %d \n", ret);
#endif
return 0;
}

int bst_to_find_occurance_of_elemnt(int arr[], int num)
{
	int low = 0;
	int high = MAX-1;
	int mid = (low + high)/2;
	int count = 0;
	while (low <= high) {
		if (arr[mid] == num) {
			count++;
			break;
		}	
		else if(arr[mid] > num)
			low = mid;
		else if(arr[mid] < num)
			high = mid - 1;
		else
			return count;
	}
return count;	
}


void show_array(int arr[])
{
	int i;
	printf("Sorted list is \n");
	for(i = 0; i < MAX; i++)
		printf("%d ", arr[i]);
}


int search_occurence_of_element_in_list(int arr[], int num)
{
	int i;
	int count = 0;
	for(i = 0; i < MAX; i++) {
		if (arr[i] == num) {
			count++;
		}	
	}
return count;     	
}


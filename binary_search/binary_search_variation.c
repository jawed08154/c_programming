#include<stdio.h>
#include<stdbool.h>

int Binary_search(int [], int , int);
int recursive_binary_search(int [], int , int , int );
int first_occur_binary_serach(int [], int , int);
int last_occur_binary_serach(int [], int , int);
int count_of_number_in_list(int [], int , int , bool);
int main()
{
	int Arr[] = {2,3,4,4,9,10,10,10,10,11,16,18,23,25};
	int num ;
	int ret, i;
	int size = sizeof(Arr)/sizeof(Arr[0]);
	printf("Sorted list \n");
	for (i = 0; i < size; i++)
		printf("%d ",Arr[i]);
	printf("\nEnter the number to search in list: ");
	scanf("%d", &num);
        //Itterative binary search
	ret = Binary_search(Arr, size, num);
	if (ret == -1)
		printf("Element not found\n");
        else
		printf("Element %d found at index %d\n",num,ret);
	//recursive binary search
        ret = recursive_binary_search(Arr, num, 0, size);
	if (ret == -1)
		printf("RECU_BST: Element not found\n");
        else
		printf("RECU_BST: Element %d found at index %d\n",num,ret);
	//finding first ocuurance of repeated number in the list
	ret = first_occur_binary_serach(Arr, num, size);
	if (ret == -1)
		printf("FIRST_OCCUR: Element not found\n");
        else
		printf("FIRST_OCCUR: Element %d first occurance found at index %d\n",num,ret);
	ret = last_occur_binary_serach(Arr, num, size);
	if (ret == -1)
		printf("LAST_OCCUR: Element not found\n");
        else
		printf("LAST_OCCUR: Element %d last occurance found at index %d\n",num,ret);
	ret = count_of_number_in_list(Arr, num, size, true);
	if (ret == -1)
		printf("Element not found\n");
	else {
	ret = (count_of_number_in_list(Arr, num, size, false) - count_of_number_in_list(Arr, num, size, true) + 1);
		printf("Total count of element %d in the list is %d\n", num,ret);
	}	

return 0;
}

int count_of_number_in_list(int Arr[], int num, int size, bool search_occurance)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int result = -1;
	while (low <= high) {
		mid = low + (high - low)/2;
		if (Arr[mid] == num) {
			result = mid;
			if (search_occurance)
				high = mid - 1;
			else
				low = mid + 1;
		}
	        else if (Arr[mid] > num)
		    high = mid -1;
	        else
		    low = mid + 1;	

	}	
return result;
}

int last_occur_binary_serach(int Arr[], int num, int size)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int result = -1;
	while (low <= high) {
		mid = low + (high - low)/2;
            if (Arr[mid] == num) {
		    result = mid;
		    low = mid + 1;
	    }
	    else if (Arr[mid] > num)
		high = mid - 1;
	    else 
	        low = mid + 1;	    

	}	
return result;
}

int first_occur_binary_serach(int Arr[], int num, int size)
{
	int low = 0;
	int high = size - 1;
	int mid ;
	int result = -1;
	while (low <= high) {
		mid = low + (high -low)/2;
		if (Arr[mid] == num) {
			result = mid;
			high = mid - 1;
		}	
		else if (Arr[mid] > num)
			high = mid - 1;
		else
			low = mid + 1;
	}

return result;	
}

int recursive_binary_search(int Arr[], int num, int low, int high)
{  
	if (low > high)
		return -1;

	int mid = (low + high)/2;

	if (Arr[mid] == num)
		return mid;
	else if (Arr[mid] > num) {
		recursive_binary_search(Arr, num, low, mid - 1);
	}
	else {
		recursive_binary_search(Arr, num, mid + 1, high);
	}	


}

int Binary_search(int Arr[], int n, int num)
{
	int low = 0, high = n-1; 
	int mid;
	while (low <= high) {
	   mid = (low + high)/2; // low + (high -low)/2 to avoid overflow
		if (Arr[mid] == num)
			return mid;
		else if (Arr[mid] < num)
			low = mid + 1;
		else
			high = mid - 1;

	}
return	-1;
}


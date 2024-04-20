#include<stdio.h>
int main(void)
{
	int arr[4];
	arr[0] = 4, arr[1]=5, arr[2]=6, arr[3]=7;
	int *p;
	p = arr; //assigning base address 
	printf("array adress is = %lu\n",&arr[0]);
	printf("value at p = %d and pointing address to = %lu\n",*p,p);
	p++;
	printf("array adress is = %lu\n",&arr[1]);
	printf("value at p = %d and pointing address to = %lu\n",*p,p);

return 0;
}

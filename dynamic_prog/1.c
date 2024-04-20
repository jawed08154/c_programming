#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *ptr = (int*)malloc(0);
	printf("address of ptr = %p ptr points to = %p\n",&ptr,ptr);
	printf("ptr value = %d\n", *ptr);
	return 0;
}

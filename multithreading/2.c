#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr= (int *)malloc(sizeof(int));
	*ptr = 5;
	printf("value at *ptr = %d address of ptr points to %p\n",*ptr, ptr);
	*ptr++;
	printf("value at *ptr = %d address of ptr points to %p\n",*ptr, ptr);

	int * ptr_1 = 1000;
char *ch = 1000;
int **pptr = 1000;
void *vd = 1000;
printf("ptr_1 = %d\n", *ptr_1);
ptr++, ch++, pptr++, vd++;
printf("ptr_1 = %d\n", *ptr_1);

return 0;
}

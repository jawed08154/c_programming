//pointers as function returns
#include<stdio.h>
#include<stdlib.h>
int Add(int* a, int* b) //called function
{
	//a and b pointer to integers local to Add
	printf("Address of a in Add =%p\n", &a);
	printf("Value in a of Add(address of a of main) = %p\n",a);
	printf("Value at address stored in a of Add = %d\n", *a);
	int c = (*a) + (*b);
	return c;
}

int main(void) //calling function
{
	int a = 2, b = 4;
	printf("Address of a in main = %p\n", &a);
	//call by refrence
	int c = Add(&a, &b); // a and b are integers local to main
	printf("Sum = %d\n", c);
return 0;
}

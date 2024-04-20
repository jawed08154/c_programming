//pointers as function returns
#include<stdio.h>
#include<stdlib.h>
void PrintHelloWorld(){
	printf("Hello World\n");
}	

int* Add(int* a, int* b) //called function
{
	int *c = (int* )malloc(sizeof(int));
	*c = *a + *b;
	//int c = (*a) + (*b);
	return c;
}

int main(void) //calling function
{
	int a = 2, b = 4;
	//call by refrence
	int* c = Add(&a, &b); // a and b are integers local to main
	PrintHelloWorld();
	printf("Sum = %d\n", *c);
return 0;
}

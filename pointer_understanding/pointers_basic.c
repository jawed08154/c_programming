#include <stdio.h>

int main(void)
{
	int a; //integer variable
	int *p; //pointer to an integer
	a = 10;
	p = &a; //initislized p with a adress
	printf("a address is %ld\n", &a);
	printf("size of integer is %ld\n", sizeof(int));
	printf("p is pointing to %ld\n", p);
	printf("value of *p = %d\n",*p);

	//pointer arthimetic
	p = p+1; //incrementing by 1 means it will point to next memory location
	printf("p+1 is pointing to %ld\n", p);
	printf("value of *(p+1) = %d\n",*(p+1)); //it's pointing to location where we didn't initialize hence garbage value 
						 //
						 //
	//Using pointers to increase the value of a
	*p = *p + 1;
	printf("value of *p = %d\n",*p); //Not getting proper output as base address of p is changed
        
	int b = 20;
	int *ptr;
	ptr = &b;
	printf("value of *ptr = %d\n", *ptr);
	*ptr = *ptr + 1;
	printf("value of *ptr = %d\n", *ptr);
        ptr = &a;

	printf("value of *ptr = %d\n", *ptr);

return 0;
}

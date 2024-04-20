#include<stdio.h>

int add(int a, int b)
{
	return a+b;
}

int main(void)
{
int c;
int (*func_ptr)(int, int);
func_ptr = add;
c = func_ptr(2,3);
printf("value post addition = %d\n",c);
return 0;
}	

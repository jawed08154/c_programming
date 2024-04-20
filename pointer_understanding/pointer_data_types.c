#include <stdio.h>

int main(void)
{
	int a = 1025;
	int *p; //pointer to an integer
	p = &a;
	printf("P pointing to Address = %ld value = %d\n",p,*p);
	printf("size of integer = %d\n", sizeof(int));
	printf("P pointing to Address = %ld value = %d\n",(p + 1),*(p+1));

	char *ch;
	ch = (char *)p; //typecasting
	printf("P pointing to Address = %ld value = %d\n",ch,*ch);
	printf("size of integer = %d\n", sizeof(char));
	printf("P pointing to Address = %ld value = %d\n",(ch + 1),*(ch+1));

	void *p0; //void pointer generic pointer
	p0 = p; //assignment is fine
	printf("p0 points to Address = %ld\n", p0); //it can print the address it's pointing to
	//printf("p0 points to value = %d\n", *p0); //derefrencing and pointer arthimetic is inavlid on void pointers


	
return 0;
}

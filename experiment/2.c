#include<stdio.h>
int main(void)
{
	union x{
	int x;
	char ch[4];
	};

	union x z;
	z.x = 1;

	printf("%d\n", z.ch[0]);
return 0;
}

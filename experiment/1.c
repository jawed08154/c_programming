#include"1.h"


void func(int i)
{

	printf("value of glb=%d,st=%d,i=%d\n",glb,st,i);

//	printf("value of glb=%d,st=%d,i=%d\n",glb,st,i);
static int st = 10;
	glb++;
	st++;
	i++;
	printf("after all func call value of glb=%d,st=%d,i=%d\n",glb,st,i);
}

int main(void)
{
	int i;
	func(i);
	printf("value of glb=%d,st=%d,i=%d\n",glb,st,i);
	st++;
	func(i);
//	func(i);
//	func(i);
	printf("after all func call value of glb=%d,st=%d,i=%d\n",glb,st,i);
return 0;
}


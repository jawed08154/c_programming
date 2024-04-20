#include<stdio.h>

int my_atoi(char *ptr)
{
	char ch;
	int result = 0;
	int num;
	while(*ptr) {
		ch = *ptr;
		num = ch - '0';
		if (num >= 0 && num <= 9)
			result = (result * 10) + num;
		else
			return -1;
		ptr++;
	}
	return result;
}



int main(void)
{
   char ch[]={"9876"};
   int num;

   num = my_atoi(ch);
   printf("number = %d\n", num);
return 0;
}

#include<stdio.h>

int add(int a, int b)
{
	
		unsigned carry;
	//while(b = ((((a ^= b) ^ b) & b) << 1) );
	while(b) {
		carry = a & b ;
		a = a^b; //addition
		b = carry << 1; //carry and shift by 1 for next addition
	}	
	return a;
}

int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common
        //set bits of x and y
        unsigned carry = x & y;

        // Sum of bits of x and y where at
        //least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

int main(void)
{
    int A = 0xABABABAB;
    int B = 0x00002200;
    int c;
    B = add(A, B);
    printf("%0X\n", B);
    //B = Add(A, B);
    //printf("%0X\n", B);
return 0;
}

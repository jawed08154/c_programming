#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, i;
	printf("Enter the size of memory required: ");
	scanf("%d", &n);
	int *p, *c;
	p = (int *)malloc(n *sizeof(int));
	printf("Address assinged to p = %p and p points to memory location=%p\n", &p,p);
	for(i = 0; i < n; i++) {
		p[i] += i;
        	printf("value at p[%d]= %d\n",i, p[i]);
    		
	}
	c = (int *)realloc(p, (n/2)*sizeof(int));
	printf("Address p points = %p, address c points = %p\n", p,c);
	for(i = 0; i < (n/2); i++)
        	printf("value at p[%d]= %d\n",i, p[i]);
             
return 0;
}

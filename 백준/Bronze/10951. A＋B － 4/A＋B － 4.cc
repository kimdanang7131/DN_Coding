#include <stdio.h>

int a,b;

int main()
{	
	while(scanf("%d %d", &a , &b) != -1)
	{
		printf("%d\n", a + b);
	}
	return 0;
}
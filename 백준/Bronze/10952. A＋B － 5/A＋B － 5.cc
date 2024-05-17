#include <stdio.h>

int a,b;

int main()
{	
	do
	{
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0)
			break;
			
		printf("%d\n", a + b);
	}while(1);

	return 0;
}
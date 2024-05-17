#include <stdio.h>

int n;

int main()
{	
	scanf("%d",&n);
	
	for(int i=0; i < n; i++)
	{
		int size = n - i - 1;
		
		for(int j = 0; j < size; j++)
		{
			printf(" ");
		}
		
		for(int k = 0; k <= i; k++)
		{
			printf("*");
		}
		
		printf("\n");
	}
	return 0;
}
#include <stdio.h>

int n;
int a,b;

int main()
{	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		a = 0, b = 0;
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",i + 1,a + b);
	}	
	return 0;
}
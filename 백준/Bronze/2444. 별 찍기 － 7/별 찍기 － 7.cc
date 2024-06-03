#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{	
	cin >> n;
	
	int cnt = 1;
	int flag = 1;
	int count = 1;
	
	for(int i=0; i < 2 * n - 1; i++)
	{
		
		if(flag == 1)
		{
			for(int j = 0; j < n - 1 - i; j++)
			{
				printf(" ");
			}			
		}
		else
		{
			for(int j = i - count - 1; j >= 0; j--)
			{
				printf(" ");
			}	
		}
		
		for(int l = 0; l < cnt; l++)
		{
			printf("*");
		}	
		cnt += 2 * flag;
		
		if(count >= n- 1)
		{
			flag = -1;
		}
		else
		{
			count++;
		}
		
		if(i < 2 * n - 2)
			printf("\n");
	}

	return 0;
}
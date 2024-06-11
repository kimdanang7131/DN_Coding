#include <iostream>

using namespace std;

int board[101][101];

int n;
int x,y;
int ret;

int main()
{	
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		
		for(int i = x; i < x +10; i++)
		{
			for(int j = y; j < y + 10; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	
	for(int i=0; i<101; i++)
	{
		for(int j=0; j<101; j++)
		{
			if(board[i][j] == 1)
				ret +=1;
		}
	}
	
	cout << ret << endl;
	return 0;
}
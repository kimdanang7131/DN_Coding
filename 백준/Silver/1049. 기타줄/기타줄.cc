#include <iostream>
#include <vector>

using namespace std;


int n;
int m;

int main()
{
	// guitar ( 1 ~ 100 ) -> 끊어진 기타줄   
	cin >> n;
	// brand  ( 1 ~  50 ) -> 개수   
	cin >> m;
	
	int minPack  = 2000;
	int minPiece = 2000;
	
	for(int i=0; i < m; i++)
	{
		int a , b;
		
		cin >> a;
		cin >> b;
		
		if(minPack > a)
			minPack = a;
			
		if(minPiece > b)
			minPiece = b;
	}
	
	int ret = 0;
	
	
	if(minPack < minPiece * 6)
	{
		while(n > 5)
		{
			ret += ( n / 6 ) * minPack;
			n %= 6;
		}
		
		if( n > 0)
		{
			ret += minPack < minPiece * n ? minPack : minPiece * n;
		}
	}
	else
	{
		ret += minPiece * n;
	}
	
	cout << ret;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int p;
int l;
int v;

int main()
{
	int i = 1;
	while(1)
	{
	   cin >> l >> p >> v;
	   
	   if(l == 0 && p == 0 && v ==0)
	   		break;
	   
	   int remain = v % p;
	   int ret = (v / p) * l + min( v%p , l);
	   
	   
	  printf("Case %d: %d\n",i++,ret);
	}
	
	return 0;
}

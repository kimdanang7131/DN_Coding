#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int a,b,c;

long long recursion(long long x)
{
	if(x == 1) return a % c;
	
	long long k = recursion( x / 2 ) % c;
	
	if(x % 2 == 0) return k*k%c;
	else return k*k%c * a%c;
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> a >> b >> c;
	
	cout << recursion(b) << endl;

	

	return 0;
} 
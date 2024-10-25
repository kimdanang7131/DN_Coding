#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibo[41];
int n;

int func = 1;
int dp;

int Fibo(int n)
{
	if(n == 1 || n == 2)
		return 1;
	else
	{
		func++;
		return Fibo(n - 2) + Fibo(n - 1);
	}
}

// n -> 5 ~ 40 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	Fibo(n);
	
	fibo[0] = 0 , fibo[1] = 1 , fibo[2] = 1;
	for(int i = 3;  i <= n; i++)
	{
		fibo[i] = fibo[i - 2] + fibo[i - 1];
		dp++;
	}
	
	cout << func << ' ' << dp << endl;
	
	return 0;

}

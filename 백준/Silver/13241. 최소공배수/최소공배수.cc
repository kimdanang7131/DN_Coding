#include <iostream>
#include <vector>
using namespace std;

int n;


int GCD(long long a,  long long b)
{
	while(b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

void LCM(long long a, long long b)
{
	long long gcd = GCD(a,b);
	
	cout << (a * b) / gcd << endl;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long a,b;
	
	cin >> a >> b;
	
	LCM(a,b);
	
    return 0;
}

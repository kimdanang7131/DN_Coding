#include <iostream>
#include <vector>
using namespace std;


int n;

int GCD(int a, int b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

void LCM(const int& a, const int& b)
{
	int gcd = GCD(a,b);
	
	cout << (a * b) / gcd << endl;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n;
	
	while(n--)
	{
		int a,b;
		cin >> a >> b;
		
		LCM(a,b);
	}

	
    return 0;
}
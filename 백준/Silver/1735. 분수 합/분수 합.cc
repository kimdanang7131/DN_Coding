#include <iostream>
#include <vector>
using namespace std;

int n;



int GCD(int a,int b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a,b,c,d;
	
	cin >> a >> b >> c >> d;
	
	int nA , dB;
	
	nA = (a*d + b*c);
	dB = b*d;
	
	int gcd = GCD(nA, dB);
	
	cout << nA / gcd << " " <<  dB  / gcd << endl;
    return 0;
}
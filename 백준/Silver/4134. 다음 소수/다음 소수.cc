#include <iostream>
#include <vector>
using namespace std;


typedef long long ll;

bool CheckPrime(ll input)
{
	ll num = input;
	
	if(num <= 1) return false;
	if(num == 2 || num == 3) return true;
	if(num % 2 == 0 || num % 3 == 0) return false;
	
	for(ll i = 5; i*i <= num; i++)
	{
		if(num % i == 0) 
			return false;
	}
	
	return true;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;
	cin >> n;
	
	for(ll i =0; i<n; i++)
	{
		ll input;
		cin >> input;
		
		while(!CheckPrime(input))
		{
			input++;
		}
		
		cout << input << endl;
	}

    return 0;
}
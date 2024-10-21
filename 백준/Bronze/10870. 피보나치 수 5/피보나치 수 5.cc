#include <iostream>
#include <vector>
using namespace std;

int n;

int Fibo(const int& num)
{
	if(num == 0)
		return 0;
	else if(num == 1 || num == 2)
		return 1;
	else
		return Fibo(num-2) + Fibo(num-1);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   	cin >> n;
   	
   	cout << Fibo(n) << endl;
   	
	return 0;
}

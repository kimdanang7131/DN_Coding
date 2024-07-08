#include <iostream>
#include <vector>

using namespace std;

int n , m;


vector<bool> primeNum;

void EratosthenesSieve(const int& s , const int& e)
{	
	primeNum.assign(e + 1 , true);
	
	if(e >= 2)
	{
		primeNum[0] = false;
		primeNum[1] = false;
	}
	
	for(int i = 2; i * i <= e; i++)
	{
		if(primeNum[i])
		{
			for(int j = i * i; j <= e; j += i)
			{
				primeNum[j] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> m >> n;
	
	if(n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	
	EratosthenesSieve(m,n);

	vector<int> primeVec;
	
	int sum = 0;
	for(int i = m; i <=n; i++)
	{
		if(primeNum[i] == true)
		{
			primeVec.push_back(i);
			sum += i;
		}
	}
	
	if(primeVec.empty())
	{
		cout << -1 << endl;
		return 0;
	}
	
	cout << sum << endl;
	cout << primeVec[0] << endl;
	
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string n;
int b;

int convertByBase()
{
    int sum(0);
    for (int i = 0; i < n.size(); i++)
    {
        int tmp = n[n.size() - i - 1];
        
        if ('0' <= tmp && tmp <= '9')
        {
            tmp = tmp - '0';
        }
        else
        {
            tmp = tmp + 10 - 'A';
        }
        
        sum += (tmp * (int)pow(b, i));
    }
	return sum;
}

int main()
{	
	cin >> n >> b;
	cout << convertByBase();
	
	return 0;
}
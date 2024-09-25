#include <iostream>
#include <vector>
using namespace std;

int n;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	int count = 0;
	
    for(int i = 1; i * i <= n; i++)
        count++;
    cout << count;

    return 0;
}
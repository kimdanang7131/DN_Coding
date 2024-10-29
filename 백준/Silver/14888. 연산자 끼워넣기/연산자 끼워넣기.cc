#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int n;
int expr[4]; // +  - * /
vector<int> numVec;

int maxNum = -1000000001;
int minNum = 1000000001;


void Solve(int result, int idx) 
{
    if (idx == n) 
	{
        maxNum = max(maxNum, result);
        minNum = min(minNum, result);
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(expr[i] > 0)
        {
            expr[i]--; 
            if(i == 0)
                Solve(result + numVec[idx], idx+1);
            else if(i == 1)
                Solve(result - numVec[idx], idx+1);
            else if(i == 2)
                Solve(result * numVec[idx], idx+1);
            else
                Solve(result / numVec[idx], idx+1);
                
            expr[i]++; 
        }
    }
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n;
    numVec.resize(n);
    for (int i = 0; i < n; i++) 
		cin >> numVec[i];
		
    for (int i = 0; i < 4; i++) 
		cin >> expr[i];

    Solve(numVec[0], 1);

    cout << maxNum << endl;
    cout << minNum << endl;
	return 0;
}
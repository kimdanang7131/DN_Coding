#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int n;
int ret;

vector<int> boardVec;

bool CheckQueen(int row, int col) 
{
    for (int i = 0; i < row; ++i) 
	{
        if (boardVec[i] == col || abs(boardVec[i] - col) == abs(i - row)) 
            return false;
    }
    return true;
}

void SetQueen(int row)
{
    if (row == n) 
	{
        ++ret;
        return;
    }
	
    for (int col = 0; col < n; col++) 
	{
        if (CheckQueen(row, col)) 
		{
            boardVec[row] = col;
            SetQueen(row + 1);
        }
    }
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n;
    boardVec.assign(n, -1);
    
    SetQueen(0);
    
    cout << ret << endl;
	return 0;
}


#include <iostream>
#include <vector>

using namespace std;

int m,n;

string board[50];

string WB[8]
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",	
	"BWBWBWBW",
};

string BW[8]
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",	
	"BWBWBWBW",
	"WBWBWBWB",	
};

int WB_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != WB[i][j])
                cnt++;
        }

    }
    return cnt;
}

int BW_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != BW[i][j])
                cnt++;
        }

    }
    return cnt;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
		
	cin >> m >> n;
	cin.ignore();
	
	
	int minNum = 99999;
	
	for(int i=0; i<m; i++)
	{
		cin >> board[i];
	}
	
	for(int i = 0; i <= m - 8; i++)
	{
		for(int j =0; j <= n - 8; j++)
		{
			int tmp;
            tmp = min(WB_cnt(i,j),BW_cnt(i,j));
            
            if(tmp < minNum) 
			{
                minNum = tmp;
            }
		}
	}
	
	cout << minNum;

	
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) 
{
    int maxSize = 0;
    int w = board.size();
    int h = board[0].size();

    vector<vector<int>> dp(w, vector<int>(h, 0));

    for (int i = 0; i < w; i++) 
    {
        dp[i][0] = board[i][0];
        maxSize = dp[i][0]; 
    }

    for (int j = 0; j < h; j++) 
    {
        dp[0][j] = board[0][j];
        maxSize = dp[0][j];
    }
    
    // 1 x 1 부터 체크 -> 왼쪽위 , 위 ,왼쪽
    for (int i = 1; i < w; i++) 
    {
        for (int j = 1; j < h; j++) 
        {
            if (board[i][j] == 1) 
            {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }

    return maxSize * maxSize;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;

    for (int h = 0; h < board.size(); h++)
    {
        for (int v = 0; v < board[h].size(); v++)
        {
            if (board[h][v] == 1)
            {
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        if ((h + i >= 0) && (h + i < board.size())
                            && (v + j >= 0) && (v + j < board[h].size()))
                        {
                            if(board[h + i][v + j] != 1)
                               board[h + i][v + j] = 2;
                        }
                            
                    }
                }
            }
        }
    }


    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[x].size(); y++)
        {
            if (board[x][y] == 0)
                ++answer;
        }
    }
    return answer;
}
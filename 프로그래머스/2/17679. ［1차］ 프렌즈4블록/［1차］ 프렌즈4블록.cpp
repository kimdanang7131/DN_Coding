#include <string>
#include <vector>

using namespace std;

// CCBDE
// AAADE
// AAABF
// CCBBF

int answer = 0;

// m 높이 , n 폭
void FlagBoard(vector<vector<bool>>& boardVec , vector<string>& board,
const int& m , const int& n, const int& x, const int& y)
{
    int r = 1 + y;
    int d = 1 + x;
    
    if(r < n && d < m)
    {
        char a,b,c,d;
        
        a = board[x][y];
        b = board[x][y+1];
        c = board[x+1][y];
        d = board[x+1][y+1];
        
        if( a == ' ' || b == ' ' || c == ' ' || d == ' ')
            return;
        
        if(a == b && b == c && c == d && d == a)
        {
            boardVec[x][y]     = true;
            boardVec[x][y+1]   = true;
            boardVec[x+1][y]   = true;
            boardVec[x+1][y+1] = true;
        }
    }
}

bool SetupBoard(vector<vector<bool>>& boardVec , vector<string>& board ,const int& m, const int& n)
{
    bool check = false;
    
    for(int i = 0; i < m - 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(boardVec[i][j] == true)
            {
                board[i][j] = false;
                answer++;
            }
            
            if(boardVec[i+1][j] == true)
            {
                board[i+1][j] = board[i][j];
                board[i][j]   = ' ';
                
                for(int k = i; k > 0; k--)
                {
                    char temp       = board[k][j];
                    board[k][j]     = board[k-1][j];
                    board[k-1][j]   = temp;
                }
                
                boardVec[i+1][j] = false;
                answer++;
                
                check = true;
            }
        }
    }
    
    
    return check;
}

int solution(int m, int n, vector<string> board) {
    
    bool check = true;
    vector<vector<bool>> boardVec(m , vector<bool>(n , false));
    
    while(check)
    {    
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                FlagBoard(boardVec, board , m , n , i, j);
            }
        }
        
        check = SetupBoard(boardVec,board,m,n);
        boardVec.assign(m , vector<bool>(n,false));
    }

    return answer;
}
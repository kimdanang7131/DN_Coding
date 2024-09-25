#include <string>
#include <vector>
#include <queue>

using namespace std;
           // 상  하 좌  우
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {  0, 0,-1, 1};

vector<vector<int>> boardVec;

typedef pair<int,int> Point;

Point Check(const Point& start, int dirX, int dirY, const int& w, const int& h) 
{
    int cx = start.first;
    int cy = start.second;

    while (true) 
    {
        int nx = cx + dirX;
        int ny = cy + dirY;

        if (nx < 0 || nx >= w || ny < 0 || ny >= h || boardVec[nx][ny] == 0) 
            break;
        
        cx = nx;
        cy = ny;
    }

    return {cx, cy};
}

int bfs(const Point& start , const Point& goal , const int& w, const int& h)
{
    queue<pair<Point,int>> q;
    vector<vector<bool>> visited(w, vector<bool>(h, false));
    
    q.push({start , 0});
    visited[start.first][start.second] = true;

    while(!q.empty())
    {
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        if (nx == goal.first && ny == goal.second) 
            return count;
        
        
        for (int i = 0; i < 4; i++) 
        {
            Point next = Check({nx, ny}, dx[i], dy[i], w, h);

            if (!visited[next.first][next.second]) 
            {
                visited[next.first][next.second] = true;
                q.push({next, count + 1});
            }
        }
    }
    
    return -1;
}



int solution(vector<string> board) {
    
    int w = board.size();
    int h = board[0].size();
    
    Point start;
    Point goal;
    
    boardVec.assign(w, vector<int>(h, 0));
    for(int i=0; i<w; i++)
    {
        for(int j=0; j < h; j++)
        {
            if (board[i][j] == '.') 
            {
                boardVec[i][j] = 1; 
            } else if (board[i][j] == 'D') {
                
                boardVec[i][j] = 0; 
            } else if (board[i][j] == 'R') 
            {
                boardVec[i][j] = 1; 
                start = {i, j};
            } else if (board[i][j] == 'G') 
            {
                boardVec[i][j] = 1; 
                goal = {i, j};
            }
        }
    }
    int answer = bfs(start, goal ,  w, h);
    return answer;
}

    
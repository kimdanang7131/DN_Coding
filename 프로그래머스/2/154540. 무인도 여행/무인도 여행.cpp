#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
vector<vector<int>> boardVec;

//            상  하  좌  우
int dx[4] = { -1, 1,  0, 0};
int dy[4] = {  0, 0, -1, 1};

int bfs(const int& x , const int& y ,const int& row , const int& col)
{
    int ret = 0;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    
    while(!q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        if(boardVec[qx][qy] == 'X' - '0')
            return 0;
        
        ret += boardVec[qx][qy];
        
        for(int i=0; i<4; i++)
        {
            int nx = dx[i] + qx;
            int ny = dy[i] + qy;
            
            if(nx < 0 || ny < 0 || nx >= row || ny >= col)
                continue;
            if(boardVec[nx][ny] == 'X' - '0')
                continue;
            if(visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    
    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int row = maps.size();
    int col = maps[0].size();
    
    boardVec.assign(row , vector<int>(col, 0));
    visited.assign(row , vector<bool>(col, false));

    // #1. 지도 만들기 2차원 벡터로
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < col ; j++)
        {
            boardVec[i][j] = maps[i][j] - '0';
        }
    }
    
    // #2. bfs를 통해 방문하지 않은 곳만 값 넣기
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < col ; j++)
        {
            if(visited[i][j] == false)
            {
                int temp = bfs(i,j, row, col);
                if(temp != 0)
                {
                    answer.push_back(temp); 
                }
            }
        }
    }
    
    if(answer.empty())
        return {-1};
    
    sort(answer.begin() , answer.end());
    
    return answer;
}
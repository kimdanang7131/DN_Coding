#include <string>
#include <vector>
#include <queue>

using namespace std;

// S : 시작 지점 -> 4
// E : 출구 -> 3
// L : 레버 -> 2
// O : 통로 -> 1
// X : 벽   -> 0

//          상 하 좌 우 
int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

vector<vector<int>> boardVec;
vector<vector<bool>> visitVec;

int sizeX, sizeY;
pair<int,int> s;

int bfs(const int& dest)
{
    visitVec.assign(sizeX , vector<bool>(sizeY, false));
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{s.first, s.second} , 0 });
    visitVec[s.first][s.second] = true;
    
    while(!q.empty())
    {
        int cx  = q.front().first.first;
        int cy  = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(boardVec[cx][cy] == dest)
        {
            s = {cx,cy};
            return cnt;
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
            
            if(nx < 0 || ny < 0 || nx >= sizeX || ny >= sizeY || boardVec[nx][ny] == 0)
                continue;
            
            if(!visitVec[nx][ny])
            {
                visitVec[nx][ny] = true;
                q.push({{nx,ny} , cnt + 1});
            }
        }
    }
    
    return -1;
}

int GetFlag(const char& c)
{
    switch(c)
    {
        case 'X':
            return 0;
            
        case 'O' :
            return 1;
            
        case 'L' : 
            return 2;
        
        case 'E' :
            return 3;
        
        case 'S' :
            return 4;
    }
    
    return -1;
}


int solution(vector<string> maps) 
{
    int answer = 0;
    
    sizeX = maps.size();
    sizeY = maps[0].size();
    
    boardVec.resize(sizeX , vector<int>(sizeY, 0));
    
    
    for(int i=0; i < sizeX; i++)
    {
        for(int j=0; j < sizeY; j++)
        {
            int c = GetFlag(maps[i][j]);
            
            if(c == 4)
            {
                s = {i , j};
            }
            
            boardVec[i][j] = GetFlag(maps[i][j]);
        }
    }
    
    int cnt = bfs(2);
    
    if(cnt == -1) return -1;
    answer = cnt;
    
    cnt = bfs(3);
    if(cnt == -1) return -1;
    answer += cnt;

    return answer;
}
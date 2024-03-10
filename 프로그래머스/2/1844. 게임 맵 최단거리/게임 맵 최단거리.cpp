#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 상 하 좌 우
int dx[4] = { -1,  1,   0, 0 };
int dy[4] = {  0 , 0 , -1, 1 };

int bfs(vector<vector<int>>& maps, int x, int y , int rowMax ,int colMax)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if( nx < 0 || nx >= rowMax || ny < 0 || ny >= colMax)
                continue;
            if(maps[nx][ny] == 0)
                continue;
            
            if(maps[nx][ny] == 1)
            {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    
    
    return maps[rowMax -1][colMax-1];
}


int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int rowNum = maps.size();
    int colNum = maps[0].size();
    
    answer = bfs(maps , 0 ,0 ,rowNum ,colNum);
    
    if(answer == 1)
        return -1;
    
    return answer;
}
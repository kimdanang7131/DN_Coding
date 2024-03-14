#include <string>
#include <vector>

using namespace std;
//    0 1 2
//    - - -
// 0) S O O
// 1) O X X
// 2) O O O 
            // 상   하   좌   우 
int dx[4] = { -1 ,  1 ,  0 , 0 };
int dy[4] = {  0 ,  0 , -1 , 1 };

int CheckDir(const char& alpha)
{
    switch(alpha)
    {
        case 'N':
            return 0;
        case 'S':
            return 1;
        case 'W':
            return 2;
        case 'E':
            return 3;
    }
}

bool MoveDir(vector<vector<int>>& routeMapVec , const char& alpha, pair<int,int>& myPos, 
             const int& maxRow , const int& maxCol)
{
    int dir = CheckDir(alpha);
    
    int nx = myPos.first  + dx[dir];  // 상하이동
    int ny = myPos.second + dy[dir];  // 좌우이동
    
    // 범위 밖을 넘어가면 return
    if(ny < 0 || ny >= maxCol || nx < 0 || nx >= maxRow)
        return false;
    else if( routeMapVec[nx][ny] == 1)
        return false;
    
    myPos.first  = nx;
    myPos.second = ny;
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int row = park.size();
    int col = park[0].size();
    
    vector<vector<int>> routeMapVec(row,vector<int>(col , 0));
    
    pair<int,int> myPos;
    
    for(int i= 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            char c = park[i][j];
            
            if(c == 'X')
            {
                routeMapVec[i][j] = 1;
                continue;
            }
            else if(c == 'S')
            {
                myPos.first  = i;
                myPos.second = j;
            }
        }
    }
    
    for(int i=0; i < routes.size(); i++)
    {
        
        char alpha = routes[i][0];
        int dist   = stoi(routes[i].substr(2,1));
        
        pair<int,int> resPos(myPos);
        
        bool CanPass = true;
        for(int j=0; j<dist; j++)
        {
            if(MoveDir(routeMapVec, alpha, resPos, row , col) == false)
            {
                CanPass = false;
                break;
            }
        }
        
        if(CanPass)
        {
            myPos = resPos;
        }
    }
    
    answer.push_back(myPos.first);
    answer.push_back(myPos.second);
    
    
    return answer;
}
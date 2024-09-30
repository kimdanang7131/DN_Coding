#include <string>
#include <vector>
#include <queue>

using namespace std;

          // 상  하  좌  우 
int dx[4] = {-1 , 1, 0 , 0};
int dy[4] = { 0 , 0,-1 , 1};

typedef pair<int,int> Point;

vector<vector<int>> boardVec;
vector<vector<bool>> visitVec;

int BFS(const Point& srt, const int& w,  const int& h)
{
    queue<pair<Point,int>> q;
    q.push({srt,0});
    
    visitVec.assign(w, vector<bool>(h,false));
    while(!q.empty())
    {
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        visitVec[nx][ny] = true;
        
        if(count >= 3)
        {
            return 1;
        }
        
        for(int i=0; i<4; i++)
        {
            int cx = nx + dx[i];
            int cy = ny + dy[i];
            
            if(cx < 0 || cx >= w || cy < 0 || cy >= h || visitVec[cx][cy])
                continue;
            if(boardVec[cx][cy] == 0) // 파티션 
                continue;
            else if(boardVec[cx][cy] == 3) // 사람
            {
                return count + 1 >= 3 ? 1 : -1;
            }
            else if(boardVec[cx][cy] == 1) // 빈 테이블
            {
                q.push({{cx,cy}, count + 1});
            }
        }
    }
        
    return 1;
}
    
    
int Play(const int& w,  const int& h)
{
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            if(boardVec[i][j] == 3)
            {
                if(BFS({i,j}, w, h) == -1)
                {
                    return 0;
                }
                    
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    
    int w = places.size();
    int h = places[0].size();
    
    for(int i=0; i < w; i++)
    {
        boardVec.assign(w , vector<int>(h,0));
        
        for(int j = 0; j < h; j++)
        {
            string s = places[i][j];
            for(int k = 0; k < 5; k++)
            {
                char c = s[k];
                switch(c)
                {
                    case 'P':
                        boardVec[j][k] = 3;
                        break;
                    case 'O':
                        boardVec[j][k] = 1;
                        break;
                    case 'X':
                        boardVec[j][k] = 0;
                        break;
                }
            }
        }
        answer.push_back(Play(w, h));
    }
    
    return answer;
}
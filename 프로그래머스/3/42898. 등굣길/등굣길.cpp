#include <vector>
#include <queue>

using namespace std;

const int MOD = 1000000007;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int bfs(int m, int n, const vector<vector<int>>& puddles) 
{
    vector<vector<int>> dist(m, vector<int>(n, -1)); // 거리 및 방문 체크
    vector<vector<int>> paths(m, vector<int>(n, 0)); // 경로의 개수 저장
    
    // 물웅덩이 위치를 -2로 설정
    for (const auto& puddle : puddles) 
    {
        dist[puddle[0] - 1][puddle[1] - 1] = -2;
    }

    // 시작 지점 설정
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    paths[0][0] = 1;

    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 2; ++i) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || dist[nx][ny] == -2) 
                continue;

            if (dist[nx][ny] == -1) 
            { 
                dist[nx][ny]  = dist[x][y] + 1;
                paths[nx][ny] = paths[x][y];
                q.push({nx, ny});
            } 
            else if (dist[nx][ny] == dist[x][y] + 1) 
            { 
                // bfs라서 경로가 합쳐지고 이동됨
                paths[nx][ny] = (paths[nx][ny] + paths[x][y]) % MOD;
            }
        }
    }

    return paths[m - 1][n - 1];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    return bfs(m, n, puddles);
}
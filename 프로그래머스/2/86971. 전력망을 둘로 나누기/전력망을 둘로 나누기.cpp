#include <string>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

vector<int> info[MAX];

int cnt;

void bfs(const int& v1 , const int& v2)
{
    queue<int> q;
    vector<bool> visited(MAX);

    q.push(v1);
    visited[v1] = true;
    visited[v2] = true;
    
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        
        for(int i=0; i<info[n].size(); i++)
        {
            int n2 = info[n][i];
            
            if(visited[n2])
                continue;
            
            cnt++;
            q.push(n2);
            visited[n2] =true;
        }
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX;

    for(vector<int>& v : wires)
    {
        info[v[0]].push_back(v[1]);
        info[v[1]].push_back(v[0]);
    }
    
    for(vector<int>& v : wires)
    {
        cnt = 1;
        int v1 = v[0];
        int v2 = v[1];
        
        bfs(v1,v2);
        answer = min(answer, abs(2 * cnt - n));
    }

    return answer;
}
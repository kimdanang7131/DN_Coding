#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visit[201];

void dfs(vector<vector<int>>& comVec , const int& s)
{
    visit[s] = true;
    
    for(int i=0; i < comVec[s].size(); i++)
    {
        if(comVec[s][i] == 1 && visit[i] == false)
        {
            dfs(comVec, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++)
    {
            if(visit[i] == false)
            {
                dfs(computers,i);
                ++answer;
            }
    }
    
    
    return answer;
}
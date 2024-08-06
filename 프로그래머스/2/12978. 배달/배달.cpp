#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

vector<vector<int>> graphVec;
vector<bool> visitVec;
vector<int> distVec;

int GetSmallIndex(const int& n)
{
    int min = INF;
    int index = 0;
    
    for(int i=1; i <= n; i++)
    {
        if(distVec[i] < min && !visitVec[i])
        {
            min = distVec[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(const int& n , const int& srt)
{
    for(int i = 1; i <= n; i++)
    {
        distVec[i] = graphVec[srt][i];
    }
    
    for(int i = 1; i <= n - 1; i++)
    {
        int current = GetSmallIndex(n);
        visitVec[current] = true;
        for(int j = 1; j <= n; j++)
        {
            if(!visitVec[j])
            {
                if(distVec[current] + graphVec[current][j] < distVec[j])
                {
                    distVec[j] = distVec[current] + graphVec[current][j];
                }
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    graphVec.assign(N + 1, vector<int>(N + 1, INF));
    visitVec.assign(N + 1 , false);
    distVec.assign(N + 1, INF);
    
    for(int i = 1; i <= N; i++)
    {
        graphVec[i][i] = 0;
    }
    
    for(int i=0; i<road.size(); i++)
    {
        int start = road[i][0];
        int end   = road[i][1];
        int cost  = road[i][2];
        
        graphVec[start][end] = min(graphVec[start][end], cost);
        graphVec[end][start] = min(graphVec[end][start], cost);
    }

    dijkstra(N, 1);
    
    for(int i = 1; i <= N; i++)
    {
        if(distVec[i] <= K)
            ++answer;
    }

    return answer;
}
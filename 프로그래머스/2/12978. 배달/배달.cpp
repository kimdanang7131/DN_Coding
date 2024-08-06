#include <iostream>
#include <vector>
using namespace std;

#define INF 500000

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    vector<vector<int>> boardVec(N + 1, vector<int>(N + 1,INF));
    
    for (int i = 1; i <= N; ++i) 
        boardVec[i][i] = 0; 
    
    for(int i=0; i<road.size(); i++)
    {
        int s = road[i][0];
        int e = road[i][1];
        int t = road[i][2];
        
        boardVec[s][e] = min(boardVec[s][e] , t);
        boardVec[e][s] = min(boardVec[e][s] , t);
    }
    
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
             for(int j = 1; j <= N; j++)
             {
                 if(boardVec[i][k] + boardVec[k][j] < boardVec[i][j])
                 {
                     boardVec[i][j] = boardVec[i][k] + boardVec[k][j];
                 }
             }
         }
    }
    
    
    for (int i = 1; i <= N; i++) 
	{
        if(boardVec[1][i] <= K)
                ++answer;
    }


    return answer;
}
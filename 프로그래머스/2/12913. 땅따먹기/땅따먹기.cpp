#include <vector>
using namespace std;

int maxCheck(const vector<int>& v , const int& idx)
{
    int max = -1;
    
    for(int i=0; i<4; i++)
    {
        if(i != idx)
        {
            if(max < v[i])
               max = v[i] ;
        }
    }
    return max;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < land[i].size(); j++)
        {
            land[i][j] += maxCheck(land[i-1] , j);
            answer = max(answer, land[i][j]);
        }
    }

    return answer;
}
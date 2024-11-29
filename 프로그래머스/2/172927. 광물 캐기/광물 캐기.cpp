#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fatigueTable[3][3]
{
    {1,1,1}, // 다이아
    {5,1,1}, // 철
    {25,5,1} // 돌
};

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if(v1[0] != v2[0])
        return v1[0] > v2[0];
    else
        return v1[1] > v2[1];
}

int solution(vector<int> picks, vector<string> minerals) 
{
    int answer = 0;
    
    int pickCount = picks[0] + picks[1] + picks[2];
    int groupCount = min(pickCount , (int)((minerals.size() + 4) / 5));
    
    vector<vector<int>> fatigueVec(groupCount);
    
    for(int i=0; i<groupCount; i++)
    {
        int diamond = 0, iron = 0, stone = 0;
        
        for(int j = 0; j < 5 && (i * 5 + j) < minerals.size(); j++)
        {
            if (minerals[i * 5 + j] == "diamond") 
            {
                diamond++;
            } 
            else if (minerals[i * 5 + j] == "iron") 
            {
                iron++;
            } 
            else 
            {
                stone++;
            }
        }
        
        fatigueVec[i] = {diamond, iron , stone};
    }
    
    sort(fatigueVec.begin(), fatigueVec.end(), cmp);
    
    for(const vector<int>& v : fatigueVec)
    {
        for(int i=0; i<3; i++)
        {
            if(picks[i] > 0)
            {
                picks[i]--;
                answer += v[0] * fatigueTable[i][0] + v[1] * fatigueTable[i][1] + v[2] * fatigueTable[i][2];
                break;
            }
        }
    }
        
    return answer;
}
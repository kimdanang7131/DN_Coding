#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

// 실패율이 같은 스테이지에 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
// 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의

bool cmp(const pair<int,float>& a , const pair<int,float>& b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    map<int,int> failMap;
    
    for(int i = 0; i < stages.size(); i++)
    {
        failMap[stages[i]] += 1;
    }
    
    vector<pair<int, float>> stageFailVector;
    int totalPlayers = stages.size();
    
    for(int i = 1; i <= N; i++)
    {
        if(failMap.count(i))
        {
            stageFailVector.push_back({i, static_cast<float>(failMap[i]) / totalPlayers});
            totalPlayers -=  failMap[i];
            
            if(totalPlayers < 0)
                break;
        }
        else
            stageFailVector.push_back({i, 0});
    }
    
    sort(stageFailVector.begin() , stageFailVector.end() , cmp);
    
    for (const pair<int, float>& sortPair : stageFailVector) 
    {
        answer.push_back(sortPair.first);
    }
    return answer;
}
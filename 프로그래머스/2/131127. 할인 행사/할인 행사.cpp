#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 바나나 3개, 사과 2개, 쌀 2개, 돼지고기 2개, 냄비 1개 -> want , number
// 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나 -> discount
//  0    1    2    3     4    5    6          7     8      9  10    11     12   13

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string,int> wantMap;
    
    for(int i=0; i < want.size(); i++)
    {
        wantMap[want[i]] = number[i];
    }
    
    
    for(int i=0; i <= discount.size() - 10; i++)
    {
        bool isPassed = false;
        
        unordered_map<string,int> tempMap(wantMap);
        
        for(int j = i; j < i + 10; j++)
        {
            if(tempMap.count(discount[j]) <= 0) // wantMap에 없다면
            {
                isPassed = false;
                break;
            }
            else // wantMap에 키가 있다면
            {
                if(tempMap[discount[j]] == 0) // 재료 없음
                {
                    isPassed = false;
                    break;
                }
                else
                {
                    isPassed = true;
                    tempMap[discount[j]]--;
                }
            }
        }
        
        if(isPassed)
            ++answer;
    }
        
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// 단 한명의 선수를 제외하고는 모든 선수 마라톤 완주함
// 마라톤 참여자 이름 participant
// 완주 선수들의 이름 completion

// completion의 길이 = participant 길이 - 1;
// 동명이인 있을 수 있다.

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin() , participant.end());
    sort(completion.begin() , completion.end());
    
    int idx = -1;
    for(int i=0; i<completion.size(); i++)
    {
        if(completion[i] != participant[i])
        {
            idx = i;
            break;
        }
    }
    
    if(idx == -1)
        answer = participant.back();
    else
        answer = participant[idx];
    
    return answer;
}
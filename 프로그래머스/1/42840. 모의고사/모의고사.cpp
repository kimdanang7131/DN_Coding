#include <string>
#include <vector>
#include <map>

using namespace std;

// 1번 :  1 , 2, ,3 ,4, 5  /// 1 , 2 ...
// 2번 : 2 , 1,  2, 3,  2, 4,  2, 5, ///   2, 1, 2, 3...
// 3번 : 3,3 1,1 2,2 4,4 5,5  ///  3,3 1,1 2,2 4,4 5,5 ...

bool CheckCorrectAnswer(const int& answer , const int& checkNum)
{
    return answer == checkNum;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> chk1 = {1,2,3,4,5};
    vector<int> chk2 = {2,1,2,3,2,4,2,5};
    vector<int> chk3 = {3,3,1,1,2,2,4,4,5,5};
    
    map<int,int> sortMap;
    
    for(int i=0; i < answers.size(); i++)
    {
        if(CheckCorrectAnswer(answers[i] , chk1[i % chk1.size()]))
           sortMap[1]++;
        if(CheckCorrectAnswer(answers[i] , chk2[i % chk2.size()]))
           sortMap[2]++;
        if(CheckCorrectAnswer(answers[i] , chk3[i % chk3.size()]))
           sortMap[3]++;
    }
    
    int min = -1;
    for(const pair<int,int> map : sortMap )
    {
        if(min < map.second)
        {
            answer.clear();
            answer.push_back(map.first);
            
            min = map.second;
        }
        else if(min == map.second)
            answer.push_back(map.first);
    }
    

           
    return answer;
}
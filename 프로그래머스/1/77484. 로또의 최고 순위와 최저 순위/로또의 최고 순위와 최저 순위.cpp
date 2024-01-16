#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    map<int,int> gradeMap;
    gradeMap.insert({6, 1});
    gradeMap.insert({5, 2});
    gradeMap.insert({4, 3});
    gradeMap.insert({3, 4});
    gradeMap.insert({2, 5});
    gradeMap.insert({1, 6});
    gradeMap.insert({0, 6});
    
    sort(win_nums.begin() , win_nums.end());
    sort(lottos.begin() , lottos.end());
     
    int count = 0;
    int zero = 0;
    
    for(int i=0; i< win_nums.size(); i++)
    {
        if(lottos[i] == 0)
        {
            ++zero;
            continue;
        }
        
        for(int j = i - zero; j < win_nums.size(); j++)
        {
            if(lottos[i] == win_nums[j])
            {
                ++count;
                break;
            }
        }
    }
    
    int min = count;
    int max = count  + zero;
    
    answer.push_back(gradeMap[max]);
    answer.push_back(gradeMap[min]);
    
    return answer;
}
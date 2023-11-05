#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    map<int,int,greater<int>> result;
    
    sort(d.begin(), d.end());
    
    if(d.size() == 1)
        return budget >= d[0]? 1 : 0;
    
    for(int i=0; i < d.size() - 1; i++)
    {
        int count = 1;
        int sum = d[i];
        
        for(int j = i + 1; j<d.size(); j++)
        {
            sum += d[j];
            
            if(sum <= budget)
                ++count;
        }
        
        result[count] = sum;
    }
    
    for(const auto& m : result)
    {
        answer = m.first;
        break;
    }
    
    return answer;
}
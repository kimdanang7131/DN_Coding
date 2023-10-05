#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int,int>& a, std::pair<int,int>& b)
{
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second > b.second;
}

int solution(vector<int> array) {
    int answer = 0;
    map<int,int> numbers;
    
    for(int i=0; i<array.size(); i++)
    {
       numbers[array[i]]++;
    }
    
    vector<pair<int,int>> max_nums(numbers.begin() , numbers.end());
    sort(max_nums.begin(), max_nums.end() , cmp);
    
    int temp_max = max_nums[0].second;
    bool diff = false;
    

    if(max_nums.size() > 1)
    {
        int count = 0;
        
        for(const auto i : max_nums)
        {
            if(i.second != temp_max)
            {               
                diff = true;
            }
            else
                ++count;
                 
        }
        
        if(!diff)
        {  
            return -1;
        }
        else
        {
            if( count >= 2 )
                  return -1;
            else   
               return max_nums[0].first;
        }
            
            
    }
    else
    {
        if(max_nums[0].first == 0)
            return 0;
        else
             return max_nums[0].first;
    }
}
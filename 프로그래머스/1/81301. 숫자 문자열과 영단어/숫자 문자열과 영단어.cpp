#include <string>
#include <vector>
#include <map>

using namespace std;

int StringToInt(const string& numStr)
{
    static map<string, int> convertMap =
    {
        {"zero"  , 0},
        {"one"   , 1},
        {"two"   , 2},
        {"three" , 3},
        {"four"  , 4},
        {"five"  , 5},
        {"six"   , 6},
        {"seven" , 7},
        {"eight" , 8},
        {"nine"  , 9}
    };

    if (convertMap.find(numStr) != convertMap.end())
        return convertMap[numStr];
    else 
        return -1;
}


int solution(string s) {
    int answer = 0;
    
    string temp;
    
    vector<int> nums;
        
    for(int i=0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            nums.push_back(s[i] - 48);
        }
        else
        {
            temp += s[i];
            
            if(StringToInt(temp) >= 0)
            {
                nums.push_back(StringToInt(temp));
                temp.clear();
            }
        }
    }
    
    int size = nums.size();
    
    for(int i = 0; i < size; i++)
    {
        int temp = 1;
        
        for(int j = i; j < size - 1; j++)
        {
            temp *=  10;
        }
        
        answer += nums[i] * temp;
    }
    
    return answer;
}
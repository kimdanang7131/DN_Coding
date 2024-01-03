#include <string>
#include <vector>
#include <stack>

using namespace std;

string ConvertBinaryNumToString(int size)
{
    int binaryNum = size;
    
    stack<int> binaryNums;
    
    while(binaryNum > 0)
    {
        int temp = binaryNum % 2;
        binaryNums.push(temp);    
        binaryNum /= 2;
    }
    
    string result = "";
    while (!binaryNums.empty())
    {
        result += to_string(binaryNums.top());
        binaryNums.pop();
    }
    
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int count = 0;
    int convertCount = 0;
    
    string str = s;
    
    while(1)
    {
        string newStr = "";
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '0')
            {
                ++count;
                continue;
            }
            
            newStr += str[i];
        }
        
        newStr = ConvertBinaryNumToString(newStr.size());
        ++convertCount;
        
        if(newStr.size() <= 1 && newStr == "1")
            break;
    
        str = newStr;
    }
    
    answer.push_back(convertCount);
    answer.push_back(count);
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char SwitchToHexa(const int& num)
{
    switch(num)
    {
        case 10:
            return 'A';
            break;
        case 11:
            return 'B';
            break;
        case 12:
            return 'C';
            break;
        case 13:
            return 'D';
            break;
        case 14:
            return 'E';
            break;
        case 15:
            return 'F';
            break;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string result = "";
    
    int count = 0;
    int size = m * t;
    
    result += '0';
    while(result.size() < size)
    {
        string temp = "";
        
        int i = count;
        while(i > 0)
        {
            int remain = i % n;
            
            if(n > 10)
            {
                if(remain >=10 && remain < 16)
                    temp += SwitchToHexa(remain);
                else
                    temp += to_string(remain);
            }
            else
            {
                temp += to_string(remain);
            }
            
            i /= n;
        }
        if(temp.size() >0)
            reverse(temp.begin() , temp.end());
        
        result += temp;
        
        ++count;
    }
    
    for(int i=0; i<result.size(); i++)
    {
        int order =  (i % m) + 1;
        if(order == p)
            answer += result[i];
        
        if(answer.size() >= t)
            break;
    }
    
    
    return answer;
}
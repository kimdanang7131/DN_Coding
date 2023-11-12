#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i < s.size(); i++)
    {
        int temp = 0;
        int remain = 0;
        
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            temp = s[i] + n;
            
            if(temp > 'Z')
            {
                remain = temp - 'Z';
                answer += 'A' + remain - 1;
                continue;
            }
            
            answer += temp;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            temp = s[i] + n;
            
            if(temp > 'z')
            {
                remain = temp - 'z';
                answer += 'a' + remain - 1;
                continue;
            }
            
            answer += temp;
        }
        else
        {
            answer += ' ';
        }
    }
    return answer;
}
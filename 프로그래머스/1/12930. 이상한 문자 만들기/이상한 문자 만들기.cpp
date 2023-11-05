#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 0;
    for(int i=0; i < s.size(); i++)
    {
        if(s[i] != ' ')
        {
            if(index & 1) // 홀수 비트연산
                answer += tolower(s[i]);
            else
                answer += toupper(s[i]);
            
            ++index;
        }
        else
        {
            answer += ' ';
            index = 0;
        }
    }
    
    
    
    
    
    
    
    
    
    

    
    return answer;
}
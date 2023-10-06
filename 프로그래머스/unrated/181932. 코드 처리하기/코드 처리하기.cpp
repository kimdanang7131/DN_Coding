#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = false;
    
    deque<char> d;
    
    for(int i=0; i<code.size(); i++)
    {
        if(code[i] == '1')
            mode = !mode;
        else
        {
            if(!mode)
            {
                if(i % 2 == 0 || i == 0)
                {
                    d.push_back(code[i]);
                }
                   
            }
            else
            {
                if(i % 2 == 1)
                {
                    d.push_back(code[i]);
                }
                   
            }
        }
    }
    
    if(!d.size())
    {
        answer ="EMPTY";
    }
    else
    {
        for(const auto i : d)
        {
            answer += i;
        }
    }
    
    return answer;
}
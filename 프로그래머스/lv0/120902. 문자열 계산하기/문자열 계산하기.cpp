#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    queue<int> temp;
    queue<char> opt;
    
    string str= "";
    
    for(int i=0; i<my_string.size(); i++)
    {
        if(isdigit(my_string[i]))
        {
            str += my_string[i];   
        }
        else if(my_string[i] != ' ')
        {
            opt.push(my_string[i]);
        }
        else
        {
            if(str.size())
            {
               temp.push(stoi(str));
               str="";                
            }
        }
    }
    
    if(str.size())
    {
       temp.push(stoi(str));
       str="";                
    }
    
    if(temp.size())
    {
       answer = temp.front();
       temp.pop();
    }
    
    while(opt.size())
    {
        if(temp.size())
        {
            switch(opt.front())
            {
                case '+':
                answer += temp.front();
                temp.pop();
                break;
                        
                case '-':
                answer -= temp.front();
                temp.pop();
                break;
                        
                default:
                break;
            }
            opt.pop();
        }
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string Rotate(string s)
{
    char temp = s.front();
    string result = s.substr(1) + temp;
    return result;
}

struct brackets
{
    char open;
    char close;
};

int solution(string s) {
    int answer = 0;
    
    brackets bkt[3];
    
    bkt[0].open  = '(';
    bkt[0].close = ')';
    
    bkt[1].open  = '[';
    bkt[1].close = ']';
    
    bkt[2].open  = '{';
    bkt[2].close = '}';
    

        
    for(int i=0; i<s.size(); i++)
    { 
        s = Rotate(s);
        bool isClose = false;
        for(int i=0; i<3; i++)
        {
            if(bkt[i].close == s.front())
            {
                isClose = true;
                break;
            }
        }
        
        if(isClose)
            continue;
        
        vector<pair<int,char>> temp;
        
        for(int j = 0; j < s.size(); j++)
        {
            for(int k=0; k<3; k++)
            {
                if(bkt[k].open == s[j]) // 여는 괄호일 시
                {
                    temp.push_back({k,s[j]});
                    break;
                }
            }
            
            for(int k=0; k<3; k++)
            {
                if(bkt[k].close == s[j])
                {
                    if(temp.empty())
                    {
                        isClose =true;
                        break;
                    }
                    
                    if(temp.back().first == k) // 괄호맞으면 그냥 break
                    {
                        temp.pop_back();
                        break;
                    }
                    else
                    {
                        isClose = true;
                        break;
                    }
                }
            }
            if(isClose)
                break;
        }
        
        if(!isClose && temp.empty())
          ++answer;
    }
    return answer;
}
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열 -> () 괄호의 짝도 모두 맞을 경우
// 균형잡힌 괄호 문자열 -> 개수만 같을 경우
// p가 이미 "올바른 괄호 문자열"이라면 그대로 return 하면 됩니다. -> stack으로 체크

bool Check(const string& str)
{
    stack<char> s;
    
    for(int i=0; i<str.size(); i++)
    {
        if(s.empty() && str[i] == ')')
            return false;
        else
        {
            if(str[i] == '(')
                s.push(str[i]);
            else
            {
                if(s.top() == '(')
                    s.pop();
            }
        }
    }
    
    return s.empty();
}

string RemoveFBAndReverse(string str)
{
    string result = "";
    for (int i = 1; i < str.size() - 1; i++)
    {
        if (str[i] == '(')
            result += ')';
        else
            result += '(';
    }
    return result;
}

string SplitString(string p)
{
    if(p.empty())
        return "";
    
    string u = "";
    string v = "";
    
    int l = 0;
    int r = 0;
    
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '(')
            l++;
        else
            r++;
        
        u += p[i];
        
        if(l == r)
        {
            v = p.substr(i + 1);
            break;
        }
    }
    
    if(Check(u))
        return u + SplitString(v);
    else
    {
        string temp = "(" + SplitString(v) + ")";
        return temp + RemoveFBAndReverse(u);
    }
}



string solution(string p) {
    return SplitString(p);
}
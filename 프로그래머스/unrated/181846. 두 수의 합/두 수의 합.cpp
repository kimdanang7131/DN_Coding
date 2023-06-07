#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string solution(string a, string b) {
    string answer = "";
    
    int diff = abs(static_cast<int>(a.size() - b.size()));
    
    if(a.size() > b.size())
    {
        for(int i=0; i< diff; i++)
            b.insert(0,"0");
    }
    else if(b.size() > a.size())
    {
        for(int i=0; i<diff; i++)
        {
            a.insert(0,"0");
        }
    }
  
    int i = a.size()-1;
    bool ten = false;
    int temp = 0;
    
    while(i >= 0)
    {
        temp = (a[i] - '0') + (b[i] - '0');
        
        if(ten)
            temp+=1;
        
        if(temp >= 10)
        {
            temp %= 10;
            answer += temp + '0';
            ten = true;
        }
        else
        {
            answer += temp + '0';
            ten = false;
        }
        --i;
        temp=0;
    }

    if(ten)
        answer+=1+'0';
    
    reverse(answer.begin(), answer.end());
    return answer;
}
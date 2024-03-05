#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> m;
    map<string,int>::iterator it;
    
    for(int i = 65; i < 91; i++)
    {
        char ch(i);
        string temp = "";
        temp +=ch;
        m[temp] = i - 64;
    }
    
    int start = 0, idx = 27;
    
    while(1)
    {
        int temp_ans = 0;
        string temp = "";
        
        int i, flag =0;
        for(i = start; i<msg.size(); i++)
        {
            temp += msg[i];
            
            if(m.find(temp) == m.end())
            {
                answer.push_back(temp_ans);
                m[temp] = idx;
                
                start = i; idx++;
                flag =1;
                break;
            }
            else
            {
                temp_ans = m[temp];
                continue;
            }
        }
        
        if(flag == 0)
        {
            answer.push_back(temp_ans);
            start = i;
        }
        if(i>=msg.size())
            break;
    }
    
    return answer;
}

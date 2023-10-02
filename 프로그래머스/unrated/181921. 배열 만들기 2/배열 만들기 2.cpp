#include <string>
#include <vector>
#include <stdbool.h>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    string tmp;
    bool chk;
    
    for(int i=l; i<=r; i++)
    {
        chk=false;
      
        tmp = to_string(i);
        for(auto a : tmp)
        {
            if(a != '0' &&  a != '5')
            {
                chk = true;
                break;
            }
        }
        
        if(!chk)
            answer.push_back(stoi(tmp));
    }
    
    if(!answer.size())
    {
        answer.push_back(-1);
    }
    return answer;
}
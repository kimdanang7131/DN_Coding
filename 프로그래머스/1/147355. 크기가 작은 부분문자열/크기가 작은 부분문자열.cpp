#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    long long answer = 0;
    
    if(t.size() < p.size())
        return stoll(t) <= stoll(p) ? 1 : 0;
        
    for(long long i=0; i <= t.size() - p.size(); i++)
    {
        string temp;
        temp = t.substr(i,p.size());
        
        if(stoll(temp) <= stoll(p))
            ++answer;
    }
    
    return answer;
}
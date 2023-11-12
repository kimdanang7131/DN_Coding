#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i=0; i < s.size(); i++)
    {
        int start = -1;
        int end   = -1;
        
        char temp = s[i];
        end = i;

        for(int j = i - 1; j >=0; j--)
        {
            if(temp == s[j])
            {
                start = j;
                break;
            }
        }
        
        if(start != -1)
        {
            answer.push_back(end - start);
        }
        else
            answer.push_back(-1);
    }
    return answer;
}
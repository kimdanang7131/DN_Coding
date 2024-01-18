#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(const string& str : targets)
    {
        int sum = 0;
        bool check =false;
        
        for(int j =0 ; j < str.size(); j++)
        {
            char alpha = str[j];
            int fIdx = 101;
            
            for(int i=0; i<keymap.size(); i++)
            {
                if(keymap[i].find_first_of(alpha) != string::npos)
                {
                    int temp = keymap[i].find_first_of(alpha);
                    
                    if(fIdx > temp)
                        fIdx = temp;
                }
            }
            
            if(fIdx == 101)
            {
                check = true;
                break;
            }
            
            sum += fIdx + 1;
        }
        
        if(sum == 0 || check)
            sum = -1;
        
        answer.push_back(sum);
    }
    return answer;
}
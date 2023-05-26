#include <string>
#include <vector>
#include <stdbool.h>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    
    for(int i=0; i<my_string.size(); i++)
    {
        bool chk = false;
        
        for(int j=0; j<indices.size(); j++)
        {     
           if(i == indices[j])
            {
                chk = true;
                break;
            }
        }
        
        if(!chk)
           answer+=my_string[i];
    }
    return answer;
}
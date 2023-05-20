#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    for(int i=1; i<numLog.size(); i++)
    {
        int sel;
        sel = numLog[i] - numLog[i-1];
        
        switch(sel)
        {
            case 1:
                answer+="w";
                break;
            case -1:
                answer+="s";
                break;
            case 10:
                answer+="d";
                break;
            case -10:
                answer+="a";
                break;
            default:
                break;
        }
    }
    return answer;
}
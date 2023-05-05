#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;

    string temp="";
    
    for(int i=0; i<my_string.size(); i++)
    {
        for(int j=i; j<my_string.size(); j++)
        {
            temp+=my_string[j];
        }
        answer.push_back(temp);
        temp="";
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}
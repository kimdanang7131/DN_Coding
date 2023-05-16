#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    
    int idx=names.size();
    int i=0;
    while(idx>0)
    {
        answer.push_back(names[i]);
        idx-=5;
        i+=5;
    }
    return answer;
}
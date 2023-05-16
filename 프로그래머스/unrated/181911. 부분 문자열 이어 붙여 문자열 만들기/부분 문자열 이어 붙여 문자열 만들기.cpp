#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    
    int count = 0;
    
    while(count < parts.size())
    {
        answer += my_strings[count].substr(parts[count][0] , parts[count][1] - parts[count][0]+1);
        ++count;
    }
    return answer;
}
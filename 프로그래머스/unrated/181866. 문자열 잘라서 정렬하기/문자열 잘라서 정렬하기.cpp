#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    
    for(auto& c : myString)
    {
        if(c == 'x')
            c = ' ';
    }
    stringstream ss;
    ss.str(myString);
    
    string temp;
    while(ss >> temp)
    {
        answer.push_back(temp);
    }
    
    sort(answer.begin() , answer.end());
    return answer;
}
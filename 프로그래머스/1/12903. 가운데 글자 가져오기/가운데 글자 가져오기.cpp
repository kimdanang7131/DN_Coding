#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int clipIndex = s.size() / 2;
    
    
    
    return s.size() % 2 == 0 ? answer = s.substr(clipIndex - 1 , 2) : answer = s.substr(clipIndex,1);
}
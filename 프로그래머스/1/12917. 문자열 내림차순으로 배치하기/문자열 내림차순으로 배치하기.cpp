#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char , int , greater<char>> sortMap;
    
    for(const char& i : s)
        sortMap[i]++;
    
    for(const pair<char,int>& i : sortMap)
    {
        for(int repeat = 0; repeat < i.second; repeat++)
           answer += i.first;
    }
    
    return answer;
}
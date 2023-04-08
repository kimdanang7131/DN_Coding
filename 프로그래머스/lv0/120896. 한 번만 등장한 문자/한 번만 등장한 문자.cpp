#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int CountAlpha(const char& c , const string& s)
{
    int count = 0;

    for (const char& i : s)
    {
        if (i == c)
            ++count;
    }
    return count;
}

string solution(string s) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        if (CountAlpha(s[i], s) == 1)
            answer += s[i];
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}
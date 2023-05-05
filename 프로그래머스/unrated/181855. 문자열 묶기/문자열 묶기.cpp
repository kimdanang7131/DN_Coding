#include <string>
#include <vector>
#include <map>

using namespace std;



int solution(vector<string> strArr) {
    int answer = 0;
    multimap<int, int> count;

    int big = 0;

    for (int i = 0; i < strArr.size(); i++)
    {
        if (big < strArr[i].length())
            big = strArr[i].length();
    }

    for (int i = 0; i <= big; i++)
    {
        count.insert({ i,0 });
    }

    for (int i = 0; i < strArr.size(); i++)
    {
        for (auto &c : count)
        {
            if (strArr[i].length() == c.first)
            {
                c.second += 1;
            }
        }
    }


    for (auto c : count)
    {
        if (answer < c.second)
            answer = c.second;
    }
    return answer;
}
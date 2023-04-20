#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;

    map<string, long long> trans;

    trans.insert({ "zero" ,0 });
    trans.insert({ "one"  ,1 });
    trans.insert({ "two"  ,2 });
    trans.insert({ "three",3 });
    trans.insert({ "four" ,4 });
    trans.insert({ "five" ,5 });
    trans.insert({ "six"  ,6 });
    trans.insert({ "seven",7 });
    trans.insert({ "eight",8 });
    trans.insert({ "nine" ,9 });

    string temp;
    string s_answer;
    for (int i = 0; i < numbers.size(); i++)
    {      
        temp += numbers[i];

        for (const auto t : trans)
        {
            if (temp == t.first)
            {
                s_answer += to_string(t.second);
                temp = "";
            }
        }
    }

    answer = stoull(s_answer);
    return answer;
}
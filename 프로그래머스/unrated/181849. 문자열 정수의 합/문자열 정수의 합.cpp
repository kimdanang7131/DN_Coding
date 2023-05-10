#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    vector<string> sp_string;
    vector<int> sp_int;
    string tmp;

    for (int i = 0; i < num_str.size(); i++)
    {
        if (i % 9 == 0  && i != 0)
        {
            sp_string.push_back(tmp);
            tmp = "";
            tmp += num_str[i];
        }
        else
        {
            tmp += num_str[i];
        }
       
    }

    if (tmp.size())
    {
        sp_string.push_back(tmp);
        tmp = "";
    }



    for (std::string s : sp_string)
    {
        int temp = stoi(s);

        while (temp > 0)
        {
            sp_int.push_back(temp % 10);
            temp /= 10;
        }
    }

    for (const auto i : sp_int)
    {
        answer += i;
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    string temp;
    char cal;

    vector<int> n;

    for (const auto c : binomial)
    {
        if (isdigit(c))
        {
            temp += c;
        }
        else
        {
            if (c == ' ')
            {
                if (temp.size())
                {
                    n.push_back(stoi(temp));
                    temp = "";
                }
            }
            else
            {
                cal = c;
            }
        }

    }

    n.push_back(stoi(temp));
    temp = "";

    switch (cal)
    {
    case '+':
        answer = n[0] + n[1];
        break;
    case '-':
        answer = n[0] - n[1];
        break;
    case '*':
        answer = n[0] * n[1];
        break;
    }
    return answer;
}
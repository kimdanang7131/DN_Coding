#include <string>
#include <vector>

using namespace std;

bool calculate_Str(string quiz)
{
    vector<int> numbers;
    vector<char> opt;

    string temp;
    int prev_index = 0;
    int next_index = 0;

    int count = 0;
    do
    {
        temp = quiz.substr(prev_index, quiz.size() - prev_index);
        next_index  = prev_index + temp.find_first_of(' ');

        bool chk_digit = false;

        temp.clear();

        for (int i = prev_index; i < next_index; i++)
        {
            if (isdigit(quiz[i]))
                chk_digit = true;

            temp += quiz[i];
        }

        if (chk_digit)
            numbers.push_back(stoi(temp));
        else
            if (temp[0] == '+' || temp[0] == '-')
                opt.push_back(temp[0]);

        temp.clear();

        prev_index = next_index + 1;

        ++count;

    } while (count < 3);

    temp = quiz.substr(quiz.find_last_of(' ') + 1, quiz.size() - quiz.find_last_of(' '));

    int result = stoi(temp);
    temp.clear();

    int numbers_result = 0;

    switch (opt[0])
    {
          case '+':
              numbers_result = numbers[0] + numbers[1];
              break;
          case '-':
              numbers_result = numbers[0] - numbers[1];
              break;
          default:
              break;
    }
    return (numbers_result == result) ? 1 : 0;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for (auto str : quiz)
        calculate_Str(str) == 1 ? answer.push_back("O") : answer.push_back("X");

    return answer;
}
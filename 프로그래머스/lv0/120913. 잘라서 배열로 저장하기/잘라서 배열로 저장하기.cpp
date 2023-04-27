#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp;
    int index = 0;

    while (1)
    {
        if (index + n >= my_str.size())
        {
            answer.push_back(my_str.substr(index, my_str.size() - index));
            break;
        }
        else
        {
            answer.push_back(my_str.substr(index, n));
            index += n;
        }
    }
    return answer;
}
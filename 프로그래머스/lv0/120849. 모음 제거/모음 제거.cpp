#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";

    string gather = "aeiou";

    for (const auto g : gather)
    {
        my_string.erase(remove(my_string.begin(), my_string.end(), g), my_string.end());
    }

    answer = my_string;
    return answer;
}
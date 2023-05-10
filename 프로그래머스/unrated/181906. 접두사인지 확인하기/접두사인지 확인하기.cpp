#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    string temp;

    for (int i = 0; i < my_string.size(); i++)
    {
        for (int j = 0; j < my_string.size()-i; j++)
        {
            temp += my_string[j];
        }

        if (temp == is_prefix)
            return 1;

        temp = "";
    }

    return answer;
}
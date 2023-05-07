#include <string.h>
#include <vector>
#include <string>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;

    for (int i = 0; i < my_string.size(); i++)
    {
        if (!strcmp(my_string.substr(i).c_str(), is_suffix.c_str()))
            answer = 1;
    }
    return answer;
}
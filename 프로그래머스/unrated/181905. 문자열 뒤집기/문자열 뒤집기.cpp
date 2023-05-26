#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    
    for(int i = 0; i < (e-s) + 1 / 2; i++)
    {
        char temp = my_string[s];
        my_string[s] = my_string[e-i];
        my_string[e-i] = temp;
        ++s;
    }
    answer = my_string;
    return answer;
}
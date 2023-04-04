#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int alpha_Start = -1;
    int alpha_End = -1;

    for (int i = 0; i < my_string.size(); i++)
    {
        if (!isalpha(my_string[i]))
        {
            if (alpha_Start < 0)
            {
                alpha_Start = i;
            }

            if (i == my_string.size() - 1)
            {
                alpha_End = i + 1;
                answer += stoi(my_string.substr(alpha_Start, alpha_End - alpha_Start));
            }
        }
        else
        {
            if (alpha_Start >= 0)
            {
                alpha_End = i;
                answer += stoi(my_string.substr(alpha_Start, alpha_End - alpha_Start));
                alpha_Start = -1;
                alpha_End   = -1;
            }
        }
    }

    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    while (s.find("Z") != string::npos)
    {
        int L_index = -1;
        int D_index = -1;
        
       
        D_index = s.find("Z");

        if (D_index != -1)
        {
            for (int i = D_index; i >= 0; i--)
            {
                if (isdigit(s[i]))
                {
                    L_index = i;
                }

                if (L_index != -1)
                {
                    if (s[i] == ' ')
                        break;
                }
            }
        }



        if (D_index != -1)
        {
            s.erase(L_index, D_index-L_index +1);
        }
    }

    string num = " ";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            answer += atoi(num.c_str());
            num.clear();
        }
        num += s[i];
    }

    if(num.size())
    {
        answer += atoi(num.c_str());
        num.clear();
    }

    return answer;
}
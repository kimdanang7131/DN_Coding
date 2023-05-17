#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter) {
    string answer = "";
    map<string, string> temp{ {".-","a"},{"-...","b"},{"-.-.","c"},{"-..","d"},{".","e"},{"..-.","f"},
 {"--.","g"},{"....","h"},{"..","i"},{".---","j"},{"-.-","k"},{".-..","l"},
 {"--","m"},{"-.","n"},{"---","o"},{".--.","p"},{"--.-","q"},{".-.","r"},
 {"...","s"},{"-","t"},{"..-","u"},{"...-","v"},{".--","w"},{"-..-","x"},
 {"-.--","y"},{"--..","z"}
    };

    string str = "";

    for (int i = 0; i < letter.size(); i++)
    {
        if (letter[i] == ' ')
        {

            for (const auto t : temp)
            {
                if (str == t.first)
                {
                    answer += t.second;
                    str = "";
                    break;
                }
            }
        }
        else
            str += letter[i];
    }

    for (const auto t : temp)
    {
        if (str == t.first)
        {
            answer += t.second;
            str = "";
            break;
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(auto& i : myString)
    {
        if(i == 'a' || i == 'A')
            i = 'A';
        else
        {
            i = tolower(i);
        }
    }
        
    answer = myString;
    return answer;
}
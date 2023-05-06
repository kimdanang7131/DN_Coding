#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    int index=0;
    
    while(index<my_string.size())
    {
        for(int i=index; i<index+m; i++)
        {
            if(i==index+c-1)
                answer+=my_string[i];
        }
        index+=m;
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    int idx= myString.find_first_of(pat);

    while(1)
    {
        if(myString.find(pat,idx) != string::npos)
        {
            ++answer;
            idx = myString.find(pat,idx) + 1;
        }
        else
            break;
        
         
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    for(int i=0; i<my_string.size(); i++)
    {
        answer=my_string.substr(0,n);   
    }
        
    return answer;
}
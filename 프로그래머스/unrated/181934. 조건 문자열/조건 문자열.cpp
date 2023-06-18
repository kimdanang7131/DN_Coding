#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    
    string sign = "";
    
    if(eq == "!")
    {
        sign += ineq;
    }
    else
    {
        sign += ineq + eq;
    }
    
    if(sign == ">=")
      answer = n >= m;
    else if(sign == "<=")
      answer = n <= m;
    else if(sign == ">")
      answer = n > m;
    else
      answer = n < m;
    
    
    return answer;
}
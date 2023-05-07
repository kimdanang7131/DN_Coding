#include <string>
#include <vector>

using namespace std;

void Change(int& a, int& b)
{
    if(a > b)
    {
        int temp=0;
        temp = a;
        a = b;
        b = temp;
    }
    else
        return;
}

long long solution(int a, int b) {
    long long answer = 0;
    
    Change(a,b);
    
    for(int i=a; i<=b; i++)
    {
        answer += i;
    }
    
    
    return answer;
}
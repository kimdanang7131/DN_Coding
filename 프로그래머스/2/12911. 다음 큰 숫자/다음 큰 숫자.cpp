#include <string>
#include <vector>

using namespace std;

bool CheckDesiredBinary(int num , const int& countNum)
{
    int count = 0;
    
    while(num != 0)
    {
        if(num % 2 == 1)
            ++count;
        
        num /= 2;
    }
    return (count == countNum) ? true : false;
}


int solution(int n) {
    int answer = 0;
    
    int findNum = n;
    int count = 0;
    
    while(n != 0)
    {
        if(n % 2 == 1)
            ++count;
        
        n /= 2;
    }
    
    
    bool isFound = false;
    
    while(!isFound)
    {
        isFound = CheckDesiredBinary(++findNum , count);
    }
    
    answer = findNum;
    
    return answer;
}
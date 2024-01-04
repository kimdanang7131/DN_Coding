#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 1;
    int halfNum = 0;
    
    halfNum = n % 2 ? ( n / 2 ) + 1 : ( n / 2 );
    
    for(int i=1; i <= halfNum; i++)
    {
        bool isChecked = false;
        int sum = i;
        
        for(int j = i + 1; j <= halfNum; j++)
        {
            sum += j;
            
            if(sum == n)
            {
                isChecked = true;
                break;
            }
            else if(sum > n)
                break;
        }
        
        if(isChecked)
            ++answer;
    }
    return answer;
}
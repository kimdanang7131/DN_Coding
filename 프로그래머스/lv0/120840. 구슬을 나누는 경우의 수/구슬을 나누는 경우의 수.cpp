#include <string>
#include <vector>
#include <math.h>


using namespace std;

double factorial(double n)
{
    
    if(n == 1)
        return 1;
    else
    {
        return n * factorial(n - 1);
    }
}

int solution(int balls, int share) {
    double answer = 1;
    
    for(int i=0; i < share; i++)
    {
        answer *= (balls - i);
    }
    
    answer /= factorial(share);
    
    return round(answer);
}
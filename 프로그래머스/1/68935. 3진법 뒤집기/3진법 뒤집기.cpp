#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> decimal;

    while(n != 0)
    {
        decimal.push_back( n % 3 );
        n /= 3;
    }
    
    for(int i=0; i < decimal.size(); i++)
    {
        answer += decimal[i] * pow(3,decimal.size() - i - 1);
    }
    return answer;
}
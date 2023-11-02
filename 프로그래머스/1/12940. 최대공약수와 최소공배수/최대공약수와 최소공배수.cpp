#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int min = 0;
    
    n < m ? min = n : min = m;
    
    vector<int> vGcd;
    
    for(int i = min; i > 0; i--)
    {
        if(n % i == 0 && m % i == 0)
        {
            vGcd.push_back(i);
        }
    }

    int gcd = vGcd[0];
    int lcm = n * m / gcd;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}
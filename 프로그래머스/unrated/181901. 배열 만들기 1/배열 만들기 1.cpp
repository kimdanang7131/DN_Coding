#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    
    int mul=1;
    while(k*mul <= n)
    {
        answer.push_back(k*mul);
        ++mul;
    }
    return answer;
}
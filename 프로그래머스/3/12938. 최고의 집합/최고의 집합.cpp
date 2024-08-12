#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s)
    {
        return {-1};
    }
    
    int base   = s / n;
    int remain = s % n;
    
    answer = vector<int>(n, base);
    
    for (int i = 0; i < remain; ++i) 
        answer[i]++;
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
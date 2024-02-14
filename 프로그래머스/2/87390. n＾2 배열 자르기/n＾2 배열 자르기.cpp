#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int w = 0;
    int h = 0;
    
    for(long long i = left; i < right + 1; i++)
    {
        h = i / n;
        w = i % n;
        
        if( h >= w + 1)
        {
            w += h - w;
        }
        
        answer.push_back(w + 1);
    }
    
    return answer;
}
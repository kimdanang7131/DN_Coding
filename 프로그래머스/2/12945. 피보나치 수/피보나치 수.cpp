#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(int n) {
    int answer = 0;
    
    vector<int> fibonacciNums;
    fibonacciNums.resize(100000 + 1);
    
    fibonacciNums[0] = 0;
    fibonacciNums[1] = 1;
    
    for(int i=2; i <= n; i++)
        fibonacciNums[i] = (fibonacciNums[i - 2] + fibonacciNums[i - 1]) % 1234567;
    
    answer = fibonacciNums[n];
    
    return answer;
}
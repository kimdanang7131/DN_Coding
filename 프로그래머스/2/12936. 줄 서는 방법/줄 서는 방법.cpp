#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// n = 1 : 1 -> 1
// n = 2 : 1 -> 2
// n = 3 : 2 -> 6
// n = 4 : 6 -> 24
// n = 5 : 24 -> 120
    
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;
    vector<long long> dp(n + 1,1);

    // 총 length 구하기 메모이제이션
    for (int i = 1; i <= n; i++) 
    {
        dp[i] = dp[i - 1] * i;
    }

    for(int i=1; i <=n; i++)
    {
        numbers.push_back(i);
    }
    
    k--;
    
    for (int i = n; i >= 1; i--) 
    {
        int idx = k / dp[i - 1]; 
        cout << idx << endl;
        answer.push_back(numbers[idx]); 
        numbers.erase(numbers.begin() + idx); 
        k %= dp[i - 1]; 
    }
    
    return answer;
}
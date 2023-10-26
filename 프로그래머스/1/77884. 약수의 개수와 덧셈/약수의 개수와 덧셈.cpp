#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    vector<int> numbers;
    
    for(int i = left; i <= right; i++)
    {
        int count = 0;
        
        for(int j=1; j <= i; j++)
        {
            if(i % j == 0)
                ++count;
        }
        
        (count & 1) ? numbers.push_back(-i) : numbers.push_back(i);
    }
    
    for(const int& num : numbers)
        answer += num;
        
    return answer;
}
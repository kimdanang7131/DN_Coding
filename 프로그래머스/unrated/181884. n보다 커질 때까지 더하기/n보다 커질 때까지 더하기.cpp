#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    
    for(auto i : numbers)
    {
        if(answer>n)
            break;
        
        answer+=i;
    }
    return answer;
}
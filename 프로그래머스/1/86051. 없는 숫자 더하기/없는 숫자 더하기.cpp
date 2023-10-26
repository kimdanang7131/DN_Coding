#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = (9 + 0) * (9 - 0 + 1) / 2;
    
    int sum = 0;
    
    for(int i=0; i<numbers.size(); i++)
        sum+= numbers[i];
    
    answer = answer - sum;
    return answer;
}
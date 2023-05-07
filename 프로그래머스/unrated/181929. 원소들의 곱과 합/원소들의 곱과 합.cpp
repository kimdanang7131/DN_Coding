#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int plus = 0;
    int mul = 1;
    
    for(const int i : num_list)
    {
        plus +=i;
        mul  *=i;
    }
    
    answer = mul < plus * plus ?  1: 0;
    return answer;
}
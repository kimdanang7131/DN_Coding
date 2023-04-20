#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int max_num = numbers.size();
    int current_num = 1;
    
    for(int i=0; i<k-1; i++)
    {
        current_num+=2;
        
        if(current_num > max_num)
        {
            current_num-=max_num;
        }
    }
    
    answer = current_num;
    return answer;
}
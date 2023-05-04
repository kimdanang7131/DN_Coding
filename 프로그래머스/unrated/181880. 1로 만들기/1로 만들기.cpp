#include <string>
#include <vector>

using namespace std;

int count_Num(int num)
{
    int count=0;
    
    while(num!=1)
    {
        if(num%2==0)
        {
            num/=2;
            count++;
        }
        else
        {
            num=(num-1)/2;
            count++;
        }
    }
    return count;
}

int solution(vector<int> num_list) {
    int answer = 0;
    
    for(const auto i : num_list)
    {
        answer += count_Num(i);
    }
    return answer;
}
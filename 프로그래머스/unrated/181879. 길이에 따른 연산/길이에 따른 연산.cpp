#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    bool isSum = false;
    
    isSum = num_list.size() >= 11 ? true : false;
    
    if(isSum)
    {
        for(const auto n : num_list)
        {
            answer+=n;
        }
    }
    else
    {
        answer=1;
        for(const auto n : num_list)
        {
            answer*=n;
        }
    }
    return answer;
}
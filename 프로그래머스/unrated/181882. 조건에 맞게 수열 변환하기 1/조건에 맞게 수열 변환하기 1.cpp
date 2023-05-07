#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(auto& a : arr)
    {
        if(a >= 50)
        {
            if(a % 2 == 0)
            {
                a /= 2;
            }
        }
        else
        {
            if(a % 2)
            {
                a *= 2;
            }
        }
        
        answer.push_back(a);
    }
    return answer;
}
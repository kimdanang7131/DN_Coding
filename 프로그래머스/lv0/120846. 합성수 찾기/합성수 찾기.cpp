#include <string>
#include <vector>

using namespace std;

int mix(const int& num)
{
    vector<int> mix_num;
    for(int i=1; i<=num; i++)
    {
        if(num%i==0)
            mix_num.push_back(i);
    }
    
    return mix_num.size();
}

int solution(int n) {
    int answer = 0;
    
    
    for(int i=1; i<=n; i++)
    {
        if(mix(i) >= 3)
            ++answer;
    }
    return answer;
}
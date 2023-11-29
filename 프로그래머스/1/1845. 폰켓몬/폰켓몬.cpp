#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size() / 2;
    map<int,int> dedupeMap;
    
    for(int i=0; i < nums.size(); i++)
    {
        dedupeMap[nums[i]] = 1;
    }
    
    return dedupeMap.size() <= size ? dedupeMap.size() : size;
}
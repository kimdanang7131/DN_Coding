#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin() , citations.end());

    int size = citations.size();
    
    for(int i = 0; i < size; i++)
    {
        int hIdx = size - i;
        
        if(citations[i] >= hIdx)
        {
           answer = hIdx;
            break;
        }
    }
   
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    vector<int> dedupeVec(1000000, 0);
    
    int sequence = 1;
    while(sequence <= elements.size())
    {
        for(int i=0; i<elements.size(); i++)
        {
            int sum = 0;
            
            for(int j = i; j < i + sequence; j++)
            {
                int temp = j;
                temp %= elements.size();
                sum += elements[temp];
            }
            
            dedupeVec[sum] = 1;
        }
        ++sequence;
    }
    for(const int& i : dedupeVec)
    {
        if(i > 0)
         answer += i;
    }
    return answer;
}
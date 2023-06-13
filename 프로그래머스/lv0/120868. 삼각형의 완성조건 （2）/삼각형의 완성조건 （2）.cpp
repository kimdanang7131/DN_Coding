#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int big   = sides[0] >= sides[1] ? sides[0] : sides[1];
    
    int small = sides[0] <= sides[1] ? sides[0] : sides[1];
    
    
    for(int i = big + 1; i < sides[0] + sides[1]; i++)
    {
        ++answer;
    }
    
    for(int i = 0; i < big; i++)
    {
        if(big <= i + small)
            ++answer;
    }
        
    return answer;
}
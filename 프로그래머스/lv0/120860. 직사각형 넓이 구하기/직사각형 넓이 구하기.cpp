#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
   
    int bigX = -256;
    int bigY = -256;
    
    int smallX = 256;      
    int smallY = 256;
    
    for(const auto& arr: dots)
    {
        bigX = max(bigX , arr[0]);
        bigY = max(bigY , arr[1]);
        
        smallX = min(smallX,arr[0]);
        smallY = min(smallY,arr[1]);
    }
    

    answer = abs((bigX - smallX) * (bigY - smallY));
    return answer;
}
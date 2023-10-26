#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    int sign = 1;
    
    for(int i=0; i<signs.size(); i++)
    {
        signs[i] == true ? sign = 1 : sign = -1;
        
        answer += sign * absolutes[i];
    }
    return answer;
}
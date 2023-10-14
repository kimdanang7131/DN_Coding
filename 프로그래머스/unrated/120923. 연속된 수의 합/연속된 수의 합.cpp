#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int firstNum = 0;
    int gaussNum = (num * (num + 1)) / 2;
    
    firstNum = (total - gaussNum) / num;
    
    for(int i=0; i<num; i++)
        answer.push_back(firstNum + i + 1);
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int,int> result;
    
    for(int i = 0; i < numbers.size() - 1; i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            int temp = numbers[i] + numbers[j];
            
            result[temp] = 1;
        }
    }
    
    for(pair<int,int> i  : result)
    {
        answer.push_back(i.first);
    }
    
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    vector<int> idx;
    
    for(int i=0; i<finished.size(); i++)
    {
        if(!finished[i])
            idx.push_back(i);
    }
    
    for(int i=0; i<todo_list.size(); i++)
    {
        for(const auto n : idx)
        {
            if(i == n)
                answer.push_back(todo_list[i]);
        }
            
    }
    return answer;
}
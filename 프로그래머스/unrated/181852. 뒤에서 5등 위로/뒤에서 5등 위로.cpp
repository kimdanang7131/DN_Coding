#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    sort(num_list.begin(), num_list.end());
    
    for(int i=0; i<num_list.size(); i++)
    {
        if(i >=5 )
        {
            answer.push_back(num_list[i]);
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    for(int i=0; i<arr.size(); i++)
    {
        int chk=0;
        for(const auto num : delete_list)
        {
            if(arr[i] == num)
            {
                chk=1;
                break;
            }
        }
        if(!chk)
            answer.push_back(arr[i]);
    }
    return answer;
}
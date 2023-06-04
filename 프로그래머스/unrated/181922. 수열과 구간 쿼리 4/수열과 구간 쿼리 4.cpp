#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    
    
    for(const auto q_Array : queries)
    {
        for(int i = q_Array[0]; i <= q_Array[1]; i++)
        {
            if(i % q_Array[2] == 0)
            {
                arr[i] +=1;
            }
        }
    }
    answer =arr;
    return answer;
}
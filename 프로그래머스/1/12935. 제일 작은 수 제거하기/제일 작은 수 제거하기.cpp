#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int min = arr[0];
    for(int i=1; i < arr.size(); i++)
    {
        if(min > arr[i])
            min = arr[i];
    }
    
    for(int i=0; i<arr.size(); i++)
    {
        if(min == arr[i])
           arr.erase(arr.begin() + i);
    }
    answer = arr;
    
    return answer;
}
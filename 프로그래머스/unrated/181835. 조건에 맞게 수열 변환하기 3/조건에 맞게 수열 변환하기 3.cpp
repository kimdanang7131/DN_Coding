#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    if(k % 2)
    {
       for(int i : arr)
       {
           answer.push_back(i*k);
       }
    }
    else
    {
    for(int i : arr)
       {
           answer.push_back(i+k);
       }
    }
    return answer;
}
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int idx=0;
    if(arr.size()==1)
    {
        answer = arr;
        return answer;
    }
    else
    {
        for(int i=2; i < arr.size(); i*=2)
       {
           ++idx;
       }
    
       answer = arr;
    
       for(int i = arr.size(); i < pow(2,idx+1); i++)
       {
           answer.push_back(0);
       }
    }
    return answer;
}
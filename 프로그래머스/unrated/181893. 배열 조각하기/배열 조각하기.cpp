#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for(int i=0; i < query.size(); i++)
    {   
        int length = arr.size();
        
        if(i % 2 == 0 || i == 0) // 짝수
        {
            for(int j = query[i] + 1; j < length; j++)
                arr.pop_back();
        }
        else // 홀수
        {      
            rotate(arr.begin() , arr.begin() + query[i] , arr.end());
            
               for(int j = 0; j< query[i]; j++)
                 arr.pop_back();
        }
    }
    answer = arr;
    
    return answer;
}
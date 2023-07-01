#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    vector<int> temp;
    
    for(int i=0; i< queries.size(); i++)
    {
        int k = queries[i][2];
            
        for(int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            if(arr[j] > k)
            {
                temp.push_back(arr[j]);
            }            
        }
        
        if(temp.size())
        {
            sort(temp.begin(),temp.end());
            answer.push_back(temp.front());
            temp.clear();
        }
        else
        {
            answer.push_back(-1);
        }
   
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int first = 0;
    int last  = 0;
    
    bool isFound = false;
    
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 2)
        {
            first = i;
            isFound=true;
            break;
        }
    }
    
    if(isFound)
    {
        for(int i=arr.size()-1; i>=0; i--)
        {
             if(arr[i] == 2)
             {
                last = i;
                break;
             }
        }    
        
        for(int i=first; i<=last; i++)
        {
            answer.push_back(arr[i]);
        }
    }
    else
    {
        answer.push_back(-1);
    }

    return answer;
}
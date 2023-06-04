#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    int first= 0;
    int last = 0;
    
    switch(n)
    {
        case 1:
            first = 0;
            last  = slicer[1];
            break;
            
        case 2:
            first = slicer[0];
            last  = num_list.size() - 1;
            break;
            
        case 3:
            first = slicer[0];
            last  = slicer[1];
            break;
            
        case 4:
            first = slicer[0];
            last  = slicer[1];
            break;
            
        default:
            break;
    }
    
    if(n == 4)
    {
        for(int i = first; i <= last; i+= slicer[2])
        {
            answer.push_back(num_list[i]);
        }
    }
    else
    {
        for(int i = first; i <= last; i++)
        {
            answer.push_back(num_list[i]);
        }
    }

    return answer;
}
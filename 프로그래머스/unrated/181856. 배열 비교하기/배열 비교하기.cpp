#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
            
    if(arr1.size() == arr2.size())
    {
        int s1,s2;
        s1 = s2 =0;
        
        for(const auto i1 : arr1)
        {
            s1 += i1;
        }
        
        for(const auto i2 : arr2)
        {
            s2 += i2;
        }
        
        if(s1 == s2)
        {
            return 0;
        }
        else
        {
            answer = s1 > s2 ? 1 : -1;         
        }
    }
    else
    {
         answer = arr1.size() > arr2.size() ? 1 : -1;
    }
    
    return answer;
}
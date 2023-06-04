#include <string>
#include <vector>
#include <stdbool.h>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    vector<int> temp;
    
    bool isSame = true;
    
    do
    {
        isSame=true;
        ++answer;
       temp = arr;
        
       for(auto& i : arr)
       {
          if(i >= 50 && i % 2 == 0)
          {
              i /= 2;
          }
          else if(i < 50 && i % 2 == 1)
          {
              i = i * 2 + 1;
          }  
       } 
        
       for(int i=0; i<arr.size(); i++)
       {
           if(temp[i] != arr[i])
           {
               isSame = false;
               break;
           }
       }
    } while(!isSame);
    
    answer--;
    return answer;
}
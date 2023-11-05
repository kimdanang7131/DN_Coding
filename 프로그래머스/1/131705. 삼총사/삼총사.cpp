#include <string>
#include <vector>
using namespace std;

int solution(vector<int> number) {
    int answer = 0; 
    int count = 1;
    
    int prev = 0;
    
    for(int i=0; i < number.size() - 2; i++)
    {      
        for(int j = i + 1; j <number.size() - 1; j++)
        {
            int temp = number[i] + number[j];
            prev = temp;
            
            for(int k = j + 1; k < number.size(); k ++)
            {
                temp += number[k];
                if(temp == 0)
                    ++answer;
                
                temp = prev;
                continue;
            }
        }
    }
    return answer;
}
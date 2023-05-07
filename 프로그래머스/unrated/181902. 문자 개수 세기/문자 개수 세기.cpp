#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);

    for(int i=0; i<my_string.size(); i++)
    {
        for(char j='A'; j<='Z'; j++)
        {
           if(j == my_string[i])
               answer[j-65]+=1;
        }
        
        for(char k ='a'; k <= 'z'; k++)
        {
            if(k==my_string[i])
                answer[k-97+26]+=1;
        }
    }
    
    return answer;
}
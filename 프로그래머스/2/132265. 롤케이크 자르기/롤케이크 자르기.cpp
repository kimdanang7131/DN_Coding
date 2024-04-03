#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int,int> cakeMapA;
    map<int,int> cakeMapB;
    
    for(int i = 0; i < topping.size(); i++)
    {
        int key = topping[i];
        cakeMapB[key] += 1;
    }
    
    for(int i = 0; i < topping.size(); i++)
    {
        int key = topping[i];
        cakeMapA[key] = 1;
        
        if(cakeMapB.count(key) > 0)
        {
            if(cakeMapB[key] <= 1)
                cakeMapB.erase(key);
            else
                cakeMapB[key] -= 1;
        }
        
        if(cakeMapA.empty() != 1 && cakeMapB.empty() != 1)
        {
            if(cakeMapA.size() == cakeMapB.size())
                ++answer;
        }
    }
        
    return answer;
}
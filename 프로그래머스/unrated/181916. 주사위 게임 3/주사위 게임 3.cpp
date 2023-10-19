#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    map<int,int> dice;
    
    dice[a]+=1;
    dice[b]+=1;
    dice[c]+=1;
    dice[d]+=1;
    
    vector<int> pq;
    
    int diceSize = dice.size();
    switch(diceSize)
    {
        case 1:
            return 1111 * a;
            break;
        case 2:
            if(dice.begin()->second == 3 || dice.begin()->second == 1)
            {
                for(auto& i : dice)
                {
                    if(i.second == 1)
                        pq.push_back(i.first);
                }
                if(pq[0] == a)
                   answer = pow((10 * b + pq[0]),2);
                else
                  answer = pow((10 * a + pq[0]),2);
            }
            else
            {
               a != b ? answer = (a + b) * abs(a-b) : answer = (a + c) * abs(a-c);
            }    
            break;
        case 3:
            
            for(auto& i : dice)
            {
                if(i.second != 2)
                    pq.push_back(i.first);
            }
            answer = pq[0] * pq[1];
            break;
            
        case 4:
            answer = dice.begin()->first;
            break;
            
        default:
            break;
    }
    return answer;
}
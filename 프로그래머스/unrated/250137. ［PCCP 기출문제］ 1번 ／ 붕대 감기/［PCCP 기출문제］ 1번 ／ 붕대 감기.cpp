#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int lastAttack = attacks.back().front();
    int hpNow = health;
    int bandageCount = 0;
    
    bool isAlive = true;

    
    for(int i=0; i <= lastAttack; i++)
    {
        bool attacked = false;
        
        for(int j = 0; j < attacks.size(); j++)
        {
            if(attacks[j][0] == i)
            {
                attacked = true;
                
                if(hpNow - attacks[j][1] <= 0)
                {
                    hpNow -= attacks[j][1];
                    isAlive = false;
                    break;
                }
                else
                {
                    hpNow -= attacks[j][1];
                    bandageCount = 0;
                }
                
            }
        }
        if(!isAlive)
            break;
        
        if(!attacked)
        {
            bandageCount++;
            
            if(hpNow + bandage[1] >= health)
                hpNow = health;
            else
                hpNow += bandage[1]; // 초당 체력 증가
            
            if(bandage[0] == bandageCount) // 시전시간
            {
                if(hpNow + bandage[2]>= health)
                   hpNow = health;
                else
                   hpNow += bandage[2]; // 추가회복량
                
                bandageCount = 0;
            }     
        }
    }
    
    return (hpNow <= 0) ? -1 : hpNow;
}
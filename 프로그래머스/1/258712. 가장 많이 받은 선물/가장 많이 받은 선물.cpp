#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct GiftStruct
{
    string name;
    int give = 0;
    int get = 0;
    int giftDeviation = 0;
};

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string,int> friendMap;
    
    int size = friends.size();
    
    GiftStruct giftStruct[size];
    
    for(int i=0; i<size; i++)
    {
        string name = friends[i];
        friendMap[name] = i;
        giftStruct[i].name = name;
    }

    vector<vector<int>> giftVec(size, vector<int>(size, 0));
    
    for(int i=0; i < gifts.size(); i++)
    {
        stringstream ss;
        string giver , getter;
        
        ss.str(gifts[i]);
        ss >> giver >> getter;
        
        
        int y = friendMap[giver];
        int x = friendMap[getter];
        
        if(i < size)
             giftVec[i][i] = -1;
        
        giftVec[y][x] += 1;
    }
    
    
    for(int i=0; i < giftVec.size(); i++)
    {
        for(int j=0; j < giftVec[0].size(); j++)
        {
            if( i == j )
                continue;
            
            giftStruct[i].give += giftVec[i][j];
            giftStruct[i].get  += giftVec[j][i];
        }
        giftStruct[i].giftDeviation = giftStruct[i].give - giftStruct[i].get;
    }
    
    vector<int> temp(size,0);
    for(int i = 0; i < giftVec.size(); i++)
    {
        for(int j = i + 1;  j < giftVec.size(); j++)
        {
            if(giftVec[i][j] > giftVec[j][i])
            {
                temp[i]++;
            }
            else if(giftVec[i][j] == giftVec[j][i])
            {
                if(giftStruct[i].giftDeviation > giftStruct[j].giftDeviation)
                {
                    temp[i]++;
                }
                else if(giftStruct[i].giftDeviation < giftStruct[j].giftDeviation)
                {
                    temp[j]++;
                }
            }
            else
                temp[j]++;
        }
    }
    
    answer = -1;
    
    for(int i=0; i <size; i++)
    {
        if(answer < temp[i])
            answer = temp[i];
    }

  
    return answer;
}
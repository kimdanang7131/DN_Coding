#include <string>
#include <map>
#include <set>

using namespace std;

//            상 하  좌  우
int nx[4] = { 0, 0, -1, 1 };
int ny[4] = { 1,-1,  0, 0 };

int GetDirection(const char& c)
{
    switch(c)
    {
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'L':
            return 2;
        case 'R':
            return 3;
    }
    
    return -1;
}

bool CanVisit(const char& dir, pair<int,int>& playerPos , map<pair<int,int>,set<int>>& InVisitedMap)
{
    if(GetDirection(dir) < 0)
        return false;
    
    int dirNum = GetDirection(dir);
    
    int px = playerPos.second + nx[dirNum];
    int py = playerPos.first  + ny[dirNum];
    
    if( px < -5 || px > 5  || py > 5 || py < -5 )
        return false;
    
    if(InVisitedMap[playerPos].find(dirNum) != InVisitedMap[playerPos].end())
    {
        playerPos.first  = py;
        playerPos.second = px;
        return false;
    }
    
    InVisitedMap[playerPos].insert(dirNum);
    playerPos.first  = py;
    playerPos.second = px;
    
    // U D L R 0 1 2 3 -> D 또는 R
    if(dirNum % 2 == 1)
         InVisitedMap[playerPos].insert(dirNum - 1);
    else // U 또는 L
         InVisitedMap[playerPos].insert(dirNum + 1);
        
    return true;
}

int solution(string dirs) {
    int answer = 0;
    
    pair<int,int> myPos(0,0);
    
    map<pair<int,int> ,set<int>> visitedMap;
    
    for(int i = 0; i < dirs.length(); i++)
    {
        char dir = dirs[i];
        
        if(CanVisit(dir , myPos , visitedMap))
            ++answer;
    }
    
    return answer;
}
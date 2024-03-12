#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 0 .#...
// 1 ..#..
// 2 ...#.
// 3 .....

// 드래그 기준
// 1. 가장 낮은 점 ( y )
// 2. 가장 낮은 점 ( x )

// 3. 가장 높은 점 ( y )
// 4. 가장 높은 점 ( x )

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
        return a.second < b.second;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<pair<int,int>> pointVec;
    
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            char c = wallpaper[i][j];
            if(c == '#')
            {
                pointVec.push_back({i,j});
            }
        }
    }
    
    int firstX, firstY , lastX, lastY = -1;
    
    firstY = pointVec.front().first;
    lastY  = pointVec.back().first + 1;
    
    sort(pointVec.begin(), pointVec.end(),  cmp);
    
    firstX = pointVec.front().second;
    lastX = pointVec.back().second + 1;
    
    answer.push_back(firstY);
    answer.push_back(firstX);
    
    answer.push_back(lastY);
    answer.push_back(lastX);
    
    return answer;
}
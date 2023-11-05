#include <string>
#include <vector>
#include <iostream>

using namespace std;

int FindBiggestSize(const vector<vector<int>>& sizeVec , int index)
{
    int bigNum = 0;
    
    for(int i=0; i<sizeVec.size(); i++)
    {
        if(bigNum < sizeVec[i][index])
            bigNum = sizeVec[i][index];
    }
    return bigNum;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int rows = sizes.size();
    int cols = sizes[0].size();
    
    vector<vector<int>> sizeVec(rows , vector<int>(cols, 0));
    
    sizeVec = sizes;
    
    for(int i=0; i<rows; i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            sizeVec[i][0] = sizes[i][1];
            sizeVec[i][1] = sizes[i][0];
        }
    }
    
    int width = 0;
    int height = 0;
    
    width  = FindBiggestSize(sizeVec , 0);
    height = FindBiggestSize(sizeVec , 1);
    
    return width * height;
}
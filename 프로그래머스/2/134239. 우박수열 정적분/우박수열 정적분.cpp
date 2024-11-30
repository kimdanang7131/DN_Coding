#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) 
{
    vector<double> answer;
    vector<int> pVec;
    pVec.push_back(k);
    
    while(k != 1)
    {
        if(k & 1)
            k = (k * 3) + 1;
        else
            k /= 2;
        
        pVec.push_back(k);
    }
    
    int n = pVec.size() - 1;
    
    for(int i=0; i < ranges.size(); i++)
    {
        int s = ranges[i][0];
        int e = n - abs(ranges[i][1]);
        
        double sum = 0.0;
        
        if(s > e || e > n)
        {
            answer.push_back(-1.0);
            continue;
        }
        
        for(int j = s ; j < e; j++)
        {
            sum += (pVec[j] + pVec[j + 1]) / 2.0;
        }
        
        answer.push_back(sum);
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

bool cmp(vector<int>& v1, vector<int>& v2)
{
    if(v1[n] == v2[n])
    {
        return v1[0] > v2[0];
    }
    else
        return v1[n] < v2[n];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    n = col-1;
    sort(data.begin(), data.end(), cmp);
    
    int ret1 = 0;
    int ret2 = 0;
    for (int i = row_begin - 1; i <= row_end - 1; i++)
    {
        int S_i = 0;
        for(int j = 0; j < data[i].size(); j++)
            S_i += data[i][j] % (i + 1);
        
        answer ^= S_i;
    }
    return answer;
}
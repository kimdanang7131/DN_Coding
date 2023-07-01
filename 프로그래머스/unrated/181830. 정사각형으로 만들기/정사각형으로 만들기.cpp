#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    
    int row    = arr.size();
    int column = arr[0].size();
    
    if(row == column)
    {
        return arr;
    }
    
    int size = row > column ? row : column;
    
    answer.resize(size, std::vector<int>(size,0));
    
    for(int i=0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if((i < row) && (j < column))
            {
                answer[i][j] = arr[i][j];
            }
        }
    }
    
    
    return answer;
}
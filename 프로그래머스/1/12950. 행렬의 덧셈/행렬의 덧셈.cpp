#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows = arr1.size();
    int cols = arr1[0].size();
    
    vector<vector<int>> answer(rows, vector<int>(cols,0)); // n x m 초기화
    
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)     
           answer[i][j] = arr1[i][j] + arr2[i][j];     
    }
    return answer;
}
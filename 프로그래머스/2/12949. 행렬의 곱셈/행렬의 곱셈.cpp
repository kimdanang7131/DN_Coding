#include <string>
#include <vector>

using namespace std;


int GetResult(const vector<vector<int>>& arr1 , const vector<vector<int>>& arr2 ,const int& x ,const int& y)
{
    int sum = 0;
    
    for(int i = 0; i < arr1[0].size(); i++)
        sum += arr1[x][i] * arr2[i][y];
    
    return sum;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows = 0;
    int cols = 0;
    
    rows = arr1.size();
    cols = arr2[0].size();
    
    vector<vector<int>> answer(rows, vector<int>(cols , 0));
    
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            answer[i][j] = GetResult(arr1,arr2,i,j);
        }
    }
    

    
  
    
    return answer;
}
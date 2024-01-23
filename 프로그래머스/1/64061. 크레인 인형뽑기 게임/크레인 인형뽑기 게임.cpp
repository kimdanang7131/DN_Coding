#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> bucket;
    
    int hMove = board.size() - 1;
    
    for(int i = 0; i < moves.size(); i++)
    {
        int wMove = moves[i] - 1;
        int pickedNum = -1;
        
        for(int j = 0; j <= hMove; j++)
        {
            if(board[j][wMove] > 0)
            {
                pickedNum = board[j][wMove];
                board[j][wMove] = 0;
                
                break;
            }
        }
         
        if(bucket.empty() && pickedNum != -1)
        {
            bucket.push(pickedNum);
            continue;
        }
        
        if(pickedNum != -1)
        {
            if(bucket.top() == pickedNum)
            {
                answer += 2;
                bucket.pop();      
            }
            else
                bucket.push(pickedNum);
        }
    }
    
    return answer;
}
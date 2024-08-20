#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int,int> Point;
vector<vector<int>> boardVec;

int Rotate(const int& w, const int& h ,const int& x1, const int& y1,const int& x2,const int& y2)
{  
    int rotateH = y2 - y1; // 가로
    int rotateV = x2 - x1; // 세로
    
    int prev = boardVec[x1][y1];
    int minRet = prev;
    
    Point movePos({x1,y1});
    
    // #1. 위쪽에서 오른쪽으로 이동
    for (int j = 0; j < rotateH; j++) 
    {
        movePos.second++; // 오른쪽으로 이동
        int curr = boardVec[movePos.first][movePos.second];
        boardVec[movePos.first][movePos.second] = prev;
        prev = curr;
        minRet = min(minRet, curr);
    }
    
    // #2. 오른쪽에서 아래로 이동
    for (int i = 0; i < rotateV; i++) 
    {
        movePos.first++; // 아래로 이동
        int curr = boardVec[movePos.first][movePos.second];
        boardVec[movePos.first][movePos.second] = prev;
        prev = curr;
        minRet = min(minRet, curr);
    }
    
    // #3. 아래쪽에서 왼쪽으로 이동
    for (int j = 0; j < rotateH; j++) 
    {
        movePos.second--; // 왼쪽으로 이동
        int curr = boardVec[movePos.first][movePos.second];
        boardVec[movePos.first][movePos.second] = prev;
        prev = curr;
        minRet = min(minRet, curr);
    }
    
    // #4. 왼쪽에서 위쪽으로 이동
    for (int i = 0; i < rotateV; i++) 
    {
        movePos.first--; // 위쪽으로 이동
        int curr = boardVec[movePos.first][movePos.second];
        boardVec[movePos.first][movePos.second] = prev;
        prev = curr;
        minRet = min(minRet, curr);
    }
    return minRet;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    boardVec.resize(rows + 1, vector<int>(columns + 1, 0));
    
    int index = 1;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            boardVec[i][j] = index++;
        }
    }
    
    for(int i=0; i < queries.size(); i++)
    {
        Point p1 = { queries[i][0] , queries[i][1] };
        Point p2 = { queries[i][2] , queries[i][3] };
        
        answer.push_back(Rotate(rows,columns, p1.first , p1.second , p2.first , p2.second));
    }
    
    return answer;
}
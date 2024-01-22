#include <string>
#include <vector>

using namespace std;

// 각 칸에 칠해진 색깔 이름이 담긴 2차원 문자열 리스트 board
// 고른 칸의 위치를 나타내는 두 정수 h , w

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int count = 0;
    int dh[4] = {0,1,-1,0};
    int dw[4] = {1,0,0,-1};
    
    int hMax = board.size();
    int wMax = board[0].size();
    
    vector<pair<int,int>> checkVec;

    for(int i=0; i < 4; i++)
    {
        int hCheck = h + dh[i];
        int wCheck = w + dw[i];
        
        if((hCheck >= 0 && hCheck < hMax) && (wCheck >=0 && wCheck < wMax))
           checkVec.push_back({hCheck , wCheck});
    }
    
    string str = board[h][w];
    
    for(int i=0; i<checkVec.size(); i++)
    {
        int hTemp = checkVec[i].first;
        int wTemp = checkVec[i].second;
        
        if(board[hTemp][wTemp] == str)
            ++answer;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

// 두 손가락의 위치가 같다면 (2580) -> 오손잡이 / 왼손잡이 기준으로 이동
// 각 번호를 누른 엄지손가락이 왼손인지 오른손이지 나타내는 연속되 문자열 형태로 return

// 왼손  L / 오른손 R 이어붙여 return


char Move(const int& num , pair<int,int>& lhs , pair<int,int>& rhs ,
          const vector<vector<int>>& numPad, const string hand)
{
    vector<int> leftVec{ 1, 4, 7};
    vector<int> rightVec{ 3, 6 ,9};
    
    // 2, 5, 8, 0 이 아닐 때
    for(int i=0; i<3; i++)
    {
        if(num == leftVec[i])
        {
            lhs.first = i;
            lhs.second = 0;
            
            return 'L';
        }
        else if( num == rightVec[i])
        {
            rhs.first = i;
            rhs.second = 2;
            
            return 'R';
        }
    }
    
    // 2 ,5 , 8, 0 이면
    
    int hNum = -1;
    int wNum = -1;
    // num의 위치 찾기
    for(int h=0; h<4; h++)
    {
        bool check = false;
        for(int w = 0; w < 3; w++)
        {
            if( numPad[h][w] == num )
            {
                hNum = h;
                wNum = w;
                check = true;
                break;
            }
        }
        
        if(check)
            break;
    }
    int distanceL = -1;
    int distanceR = -2;
    
    distanceL = abs(hNum - lhs.first) + abs(wNum - lhs.second);
    distanceR = abs(hNum - rhs.first) + abs(wNum - rhs.second);
    
    if(distanceL == distanceR)
    {
        if(hand == "left")
        {
            lhs.first = hNum;
            lhs.second = wNum;
            return 'L';
        }
        else
        {
            rhs.first = hNum;
            rhs.second = wNum;
            return 'R';
        }
    }
    
    
    if(distanceL < distanceR)
    {
        lhs.first = hNum;
        lhs.second = wNum;
        return 'L';
    }
    else
    {
        rhs.first = hNum;
        rhs.second = wNum;
        return 'R';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 4 행 3열로 초기화
    vector<vector<int>> numPad
    {
        { 1 , 2 , 3},
        { 4 , 5 , 6},
        { 7 , 8 , 9},
        { 10, 0 , 20}
    };
    

    
    pair<int,int> lhs;
    pair<int,int> rhs;
    
    lhs = make_pair(3, 0);
    rhs = make_pair(3, 2);
    
    
    for(int i=0; i<numbers.size(); i++)
    {
        answer += Move(numbers[i] , lhs , rhs , numPad , hand);
    }
    
    
    return answer;
}
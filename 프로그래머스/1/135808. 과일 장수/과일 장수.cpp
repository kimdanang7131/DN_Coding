#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// k점이 최상품의 사과
// 1점이 최하품의 사과

// 한상자 가격
// m개씩 담아 포장
// 가장 낮은 점수가 p ( 최소 1점 ) -> p * m
// 남은 사과 버림

// 이익이 발생하지 않는 경우 0을 return
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.rbegin() , score.rend());
    
    int packCount = score.size() / m; // 횟수
      
    for(int i = 0; i < packCount; i++)
    {
        int interval = i * m; 
        
        int minNum =  k + 1;
        
        for(int j = 0; j < m; j++)
        {
            if(score[interval + j] < minNum)
                minNum = score[interval + j];
        }       
        answer += (minNum * m);
    }
    

    return answer;
}
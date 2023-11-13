#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n)
    {
        if(n / a == 0) // 더이상 나눌 수 없을때
        {
            if(n % a == 0) // 병 받을 수 있음
            {
                answer += (n / a) * b; // 지금까지 받은 병 
                n = (n / a) * b; // 소지품 n개의 병 -> a개의 병으로 교환
                continue;
            }
            else
                break;
        }
        
        int remain = n % a; // 교환하고 남은 병
        answer += (n / a) * b; // 지금까지 받은 병 
        n = (n / a) * b; // 소지품 n개의 병 -> a개의 병으로 교환
        n += remain;    // 병 b개 추가 , 남은 병 추가
    
    }
    
    
    return answer;
}
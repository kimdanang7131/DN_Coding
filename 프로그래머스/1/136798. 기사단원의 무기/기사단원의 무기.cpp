#include <string>
#include <vector>

using namespace std;

// 본인 기사 번호의 약수 개수에 해당하는 공격력을 가진 무기 구매
// 공격력 제한 수치 정함
// 제한수치보다 큰 공격력을 가진 무기를 구매하는 기사는 협약기관에서 정한 공격력을 가지는 무기 구매

// 기사단원의 수 number
// 제한수치 limit
// 제한수치 초과했을때의 무기 공격력 power

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1;  i<=number; i++)
    {
        int cnt = 1;
        
        for(int j=1; j<= i/2; j++)
        {
            if(i%j == 0)
                cnt++;
        }
        
        (cnt > limit) ? answer += power : answer += cnt;
    }
    return answer;
}
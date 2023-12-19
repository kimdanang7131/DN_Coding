#include <string>
#include <vector>

using namespace std;

int EratosthenesSieve(int limit)
{
    vector<bool> primes(limit + 1 , true); // limit까지 검사해야하므로 + 1 (size)
    primes[0] = primes[1] = false; // 0과 1은 false -> 2부터 시작
    
    for(int i = 2; i * i <= limit; i++)
    {
        if(primes[i])
        {
            for(int j = i * i; j <= limit; j += i)
                primes[j] = false; // 2의배수 다 지우고 , 3의배수 다 지우고 .. 5의배수 지우고...
        }
    }
    
    int result = 0;
    for(int primeNum =2; primeNum <= limit; primeNum++)
    {
        if(primes[primeNum])
            ++result;
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    
    answer = EratosthenesSieve(n);
    return answer;
}
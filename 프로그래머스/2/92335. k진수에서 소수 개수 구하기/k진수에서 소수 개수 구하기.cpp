#include <string>
#include <vector>
#include <cmath>

using namespace std;

// n이 정수 , k가 변환할 진수
void cardConv(int n, int k , string& t)
{
    char dchar[] = "0123456789";
    
    while(n)
    {
        t.push_back(dchar[n % k]);
        n /= k;
    }
    
    if(t.size())
    {
        for(int i=0; i<t.size() / 2; i++)
        {
            char temp = t[i];
            t[i] = t[t.size() - 1 - i];
            t[t.size() -1 -i] = temp;
        }
    }
    
}

bool isPrime(const long long& num)
{
    if(num <= 1) return false;
    
    int sqrtNum = sqrt(num);
    
    for(long long i=2; i<= sqrtNum; i++)
    {
        if(num% i == 0)
            return false;
    }
    return true;
}



int solution(int n, int k) {
    int answer = 0;
    
    string str = "";
    cardConv(n, k, str);

    string temp ="";
    for(int i=0; i < str.size(); i++)
    {
        if(str[i] == '0')
        {
            if(temp.size() > 0)
            {
                if(isPrime(stoll(temp)))
                   ++answer;
                
                temp = "";
                
                continue;
            }
        }
        
        temp += str[i];
    }
    
 
    if(temp.size() > 0)
    {
        long long tNum = stoll(temp);
        
        if(tNum > 0)
        {
            if(isPrime(tNum))
            ++answer;
        }
        
    }              
    
    return answer;
}
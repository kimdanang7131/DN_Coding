#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> FindDivisors(const int& num)
{
    vector<int> divisors;
    
    if(!num)
        return divisors;   
        
    if(num == 1)
    {
        divisors.push_back(1);
        return divisors;
    }
    
    divisors.push_back(1);
   
    
    for(int i=2; i <= num / 2; i++)
    {
        if(num % i)
            continue;
        
        divisors.push_back(i);
    }
     divisors.push_back(num);
    
    return divisors;
}

void Swap(int& a , int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisors(yellow,0);
    
    divisors = FindDivisors(yellow);
    
    for(int i : divisors)
    {       
        int temp = 0;
        temp = (i * 2) + (yellow / i) * 2 + 4;
        
        int w = i;
        int v = yellow / i;
        
        if(w < v)
            continue;
                
        if(temp == brown)
        {
            answer.push_back(w + 2);
            answer.push_back(v + 2);
            break;
        }
    }
    return answer;
}
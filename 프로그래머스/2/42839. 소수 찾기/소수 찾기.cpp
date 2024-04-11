#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> primeSet;
set<int> answerSet;

vector <bool> check; 
vector <char> v;

void EratosthenesInit(const int& n)
{
    vector<bool> primeVec(n + 1 , true);
    primeVec[0] = false;
    primeVec[1] = false;
    
    for(int i = 2; i * i <= n; i++)
    {
        if(primeVec[i])
        {
            for(int j = i * i; j <= n; j += i)
                primeVec[j] = false;
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(primeVec[i])
            primeSet.insert(i);
    }
}

bool CheckPrimeNum(const int& primeNum)
{
    return primeSet.find(primeNum) != primeSet.end();
}

void dfs(int level, string s)
{   
    if(level >= 1)
    {
        if(CheckPrimeNum(stoi(s))) 
            answerSet.insert(stoi(s)); 
    }
    
    for(int i=0; i<v.size(); i++)
    {
        // 방문되었다면 넘어가기
        if(check[i])
            continue; 
        
        // 방문처리
        check[i]=true; 
        dfs(level+1, s+v[i]); 
        
        // 백트래킹
        check[i]=false; 
    }   
}

bool compare(char a, char b)
{
    return a > b;
}

int solution(string numbers) {
    
    string temp;
    temp = numbers;

    sort(temp.begin(), temp.end(),compare);
    
    EratosthenesInit(stoi(temp));
    
    // char 벡터로 변환하여 저장
    for(int i=0; i < numbers.size(); i++) 
        v.push_back(numbers[i]);       
    
    // char 벡터의 크기로 방문을 기록하기 위한 bool vector
    check.resize(v.size(),false); 
    dfs(0, "");    
    
    return answerSet.size();
}
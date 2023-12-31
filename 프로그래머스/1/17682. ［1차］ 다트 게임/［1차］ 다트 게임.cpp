#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

// 3번의 기회
// S D T 1제곱 ,2제곱,3제곱
// * , # 현재점수,이전점수 모두 2배 / # 현재점수 마이너스
// * 첫번째시 2배
// * * 중첩 -> 4배?
// * # 중첩 -> #의 점수 -2배
// S D T 점수마다 하나씩 존재
// * # 점수마다 둘중 하나만 존재, 존재안할수도있음

// 점수 : 0 ~ 10까지의 정수
// 보너스 : S D T 중 하나
// 옵션 : * 이나 # 중 하나


void CalToken(int c , vector<int>& tempVec , const int& start , const int& count , const int& caseIndex)
{
    if(c == '*')
    {
        for(int i=start; i<start + count; i++)
        {
            tempVec[i] *= 2;
        }
    }
    else if(c == '#')
    {
        tempVec[caseIndex] *= -1;
    }


}

int solution(string dartResult) {
    int answer = 0;
    
    vector<string> scoreVec;
    map<int, char> tokenMap;
        
    int count = -1;
    
    for(int i=0; i<dartResult.size(); i++)
    {
        if(dartResult[i] == '*' || dartResult[i] == '#')
        {
            tokenMap[count] = (dartResult[i]);
            dartResult[i] = ' ';
        }
        else if(isalpha(dartResult[i]))
        {
            count++;
        }
    }   
    
    stringstream ss;
    ss.str(dartResult);
    string temp;
    
    while(ss >> temp)
    {
        scoreVec.push_back(temp);
    }
    
    
    
    vector<int> tempVec;
    
    for(string s : scoreVec)
    {   
        string digitStr = "";
        
        
        for(int i=0; i < s.size(); i++)
        {
            int cTemp = s[i];
            
            if(isdigit(cTemp))
            {
                digitStr += s[i];
            }
            else
            {
                int digit = stoi(digitStr);
                int powNum = 0;
                
                
                switch(cTemp)
                {
                    case 'S':
                        powNum = pow(digit, 1);
                        tempVec.push_back(powNum);
                        break;
                    case 'D':
                        powNum = pow(digit, 2);
                        tempVec.push_back(powNum);
                        break;
                    case 'T':
                        powNum = pow(digit, 3);
                        tempVec.push_back(powNum);
                        break;
                    default:
                        break;
                }
                digitStr = ""; 
            }
        }
    }
    
    for(const pair<int,char>& token : tokenMap)
    {
        int tokenIndex = token.first;
        char c = token.second;
        
        switch(tokenIndex)
        {
            case 0 :
                CalToken(c,tempVec,0,1,0);
                break;
            case 1:
                CalToken(c,tempVec,0,2,1);
                break;
            case 2:
                CalToken(c,tempVec,1,2,2);
                break;      
        }
    }
    
    for(const int& i : tempVec)
    {
        answer += i;
    }
    return answer;
}
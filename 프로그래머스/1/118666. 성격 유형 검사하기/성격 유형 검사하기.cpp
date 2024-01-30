#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 하나의 지표에서 각 성격 유형 점수가 같으면, 두 성격 유형 중 사전 순으로 빠른 성격 유형을 검사자의 성격 유형

// 질문마다 판단하는 지표를 담은 1차원 문자열 배열 survey
// 검사자가 각 질문마다 선택한 선택지를 담은 1차원 정수 배열 choices

// survey[i]의 첫 번째 캐릭터는 i+1번 질문의 [[비동의 관련]] 선택지를 선택하면 받는 성격 유형
// survey[i]의 두 번째 캐릭터는 i+1번 질문의 [[동의 관련  ]] 선택지를 선택하면 받는 성격 유형

struct FSurvey
{
    int scoreFirst  = 0;
    int scoreSecond = 0;
    string category = "";
};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    vector<FSurvey> surveyCollect(8);
    
    surveyCollect[0].category = "RT";
    surveyCollect[1].category = "TR";
    
    surveyCollect[2].category = "CF";
    surveyCollect[3].category = "FC";
    
    surveyCollect[4].category = "JM";
    surveyCollect[5].category = "MJ";
    
    surveyCollect[6].category = "AN";
    surveyCollect[7].category = "NA";
    

    unordered_map<int,int> choiceMap
    {
        { 1 , 3 }, { 2 , 2 }, { 3 , 1 },
                   { 4 , 0 },
        { 5 , 1 }, { 6 , 2 }, { 7 , 3 }
    };
    
    for(int i=0; i < choices.size(); i++)
    {
        int fIdx = -1;
        for(int j=0; j< surveyCollect.size(); j++)
        {
            if(surveyCollect[j].category == survey[i])
            {
                fIdx = j;
                break;
            }
        }
        
        if(fIdx != -1)
        {  
            int choiceNum = choices[i];
                
            if( choiceNum < 4 )
            {
                surveyCollect[fIdx].scoreFirst  += choiceMap[choiceNum];
            }
            else if( choiceNum > 4)
            {
                surveyCollect[fIdx].scoreSecond += choiceMap[choiceNum];
            }
        }
    }
    
    
    vector<FSurvey> surveyResult(4);
    surveyResult[0].category = "RT";
    surveyResult[1].category = "CF";
    surveyResult[2].category = "JM";
    surveyResult[3].category = "AN";
    
    for(int i=0; i < surveyCollect.size(); i++)
    {
        int sFirst  = surveyCollect[i].scoreFirst;
        int sSecond = surveyCollect[i].scoreSecond;
        
        if(i & 1)
        {
            int temp = sFirst;
            sFirst  = sSecond;
            sSecond = temp;
        }
        
        surveyResult[i / 2].scoreFirst  += sFirst;
        surveyResult[i / 2].scoreSecond += sSecond;
    }

    
    for(int i=0; i < surveyResult.size(); i++)
    {
        char f = surveyResult[i].category.front();
        char b = surveyResult[i].category.back();
        

        
        if(surveyResult[i].scoreFirst == surveyResult[i].scoreSecond)
        {
            answer += (f <= b ) ? f : b;
        }
        else
        {
            answer += (surveyResult[i].scoreFirst > surveyResult[i].scoreSecond) ? f : b;
        }
    }
    
    return answer;
}
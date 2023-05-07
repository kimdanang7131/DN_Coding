#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double GetAvg(vector<int> score)
{
    int sum = 0;
    for(const auto s : score)
    {
        sum+=s;
    }
    
    return sum / (double)score.size();
}

vector<int> Sort_Grade(vector<double> answer)
{
    vector<int> temp;
    int grade= -10;
    int count=0;

    while(count < answer.size())
    {     
         int overlap = 0;
         double big = 0;
        
         for(auto a : answer)
         {
             if(big <= a)
                big = a;
         }
         
         for(int i=0; i<answer.size(); i++)
         {
             if(answer[i] == big)
             {
                 answer[i] = grade;
                 ++overlap;
                 ++count;
             }
         }   
        
         grade+=overlap; 
    }
    for(int i=0; i<answer.size(); i++)
    {
        temp.push_back((int)answer[i]+11);
    }
    
    return temp;
}


vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<double> temp;
    
    for(int i=0; i<score.size(); i++)
    {
        temp.push_back(GetAvg(score[i]));
    }
    
    answer = Sort_Grade(temp);
    return answer;
}
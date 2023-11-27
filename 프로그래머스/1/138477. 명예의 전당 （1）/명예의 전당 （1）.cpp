#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> hallOfFame;
        

    int minNum = 2001;
    for(int i = 0; i < score.size(); i++)
    {
        if(i < k) // k 공간만큼 넣기
        {
            hallOfFame.push_back(score[i]); // 명예의 전당 등록 
            
            minNum = min(minNum , score[i]);   
            answer.push_back(minNum); 
        }
        else
        {
            int temp = 2001;
                
            for(const int& num : hallOfFame)
                temp = min(temp , num);
            
            if(score[i] > temp)
            {
                for(int j = 0; j < hallOfFame.size(); j++)
                {
                    if(hallOfFame[j] == temp)
                    {
                        hallOfFame[j] = score[i];
                        break;
                    }
                }
            } 
            
            temp = 2001;
            
            for(const int& num : hallOfFame)
                temp = min(temp , num);
            
            answer.push_back(temp);       
        }
    }
    return answer;
}
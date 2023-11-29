#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int size1 = cards1.size();
    int size2 = cards2.size();
    
    int card1Count = 0;
    int card2Count = 0;
    
    for(int i=0; i < goal.size(); i++)
    {
        if(card1Count < size1)
        {
            if(goal[i] == cards1[card1Count])
            {
                card1Count++;
                continue;
            }
        }
        
        if(card2Count < size2)
        {
            if(goal[i] == cards2[card2Count])
            {
                card2Count++;
                continue;
            }
        }
        
        answer = "No";
        return answer;
    }
    
    answer = "Yes";
    return answer;
}
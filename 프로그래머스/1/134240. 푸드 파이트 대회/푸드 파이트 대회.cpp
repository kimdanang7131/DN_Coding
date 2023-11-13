#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    vector<int> temp;
    
    for(int i=0; i<food.size(); i++)
    {
        food[i] = food[i] / 2;
    }

    for(int i=1; i <food.size(); i++)
    {
        for(int j=0; j<food[i]; j++)
        {
            temp.push_back(i);
        }
    }
    
    temp.push_back(0);
    
    for(int i=food.size() - 1; i > 0; i--)
    {
        for(int j=0; j<food[i]; j++)
        {
            temp.push_back(i);
        }
    }
    
    for(int i=0; i<temp.size(); i++)
    {
        answer += temp[i] + '0';
    }
    
    
    return answer;
}
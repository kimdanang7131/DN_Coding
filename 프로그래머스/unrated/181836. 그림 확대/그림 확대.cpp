#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for(int i=0; i<picture.size(); i++)
    {
        string temp = "";
        for(int j=0; j<picture[i].size(); j++)
        {
            for(int l=0; l<k; l++)
            {
                temp += picture[i][j];
            }                            
        }
        for(int p=0; p<k; p++)
         answer.push_back(temp);
    }
    
    return answer;
}

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) 
{
    vector<int> answer(emergency.size());

    answer = emergency;

    int order = 1;
    int big = 0;

    int index = 0;

    for (int i = 0; i < emergency.size(); i++)
    {
        for (int j = 0; j < emergency.size(); j++)
        {
            if (big < emergency[j])
            {
                big = emergency[j];
                order = j;
            }

            if (j == emergency.size()-1)
            {
                emergency[order] = 0;
                big = 0;
            }
        }
        answer[order] = ++index;
    }

    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// -20 -15 / -18 -13 / -14 -5 / -5 -3

bool compare(const vector<int>& p1, const vector<int>& p2) 
{
    return p1[1] < p2[1];
}

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camPos = -30001;
    
    sort(routes.begin(), routes.end(), compare);
    
    for (const auto& route : routes) 
    {
        if (camPos < route[0]) 
        {
            camPos = route[1];  
            answer++;
        }
    }

    return answer;
}
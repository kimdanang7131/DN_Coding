#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for(const auto s : order)
    {
        if(s == "icecafelatte" || s == "cafelatteice"
          || s == "hotcafelatte" || s == "cafelattehot"
           || s == "cafelatte")
            answer+=5000;
        else
            answer+=4500;
    }
    
    return answer;
}
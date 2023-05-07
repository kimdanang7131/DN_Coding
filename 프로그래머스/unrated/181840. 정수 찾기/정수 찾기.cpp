#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(vector<int> num_list, int n) {
    int answer = 0;
    
    for(const int i:num_list)
    {
        if(i == n)
            return 1;
    }
    
    return answer;
}
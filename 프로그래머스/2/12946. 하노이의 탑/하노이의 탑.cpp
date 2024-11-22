#include <string>
#include <vector>

using namespace std;

void HanoiTower(int n, int from, int by, int to , vector<vector<int>>& answer)
{
    if(n == 0)
        return;
    
    // n - 1개를 B로 옮긴다
    HanoiTower(n - 1, from, to , by, answer);
    // A를 C로 옮긴다
    answer.push_back({from, to});
    // n- 1개를 B->C로 옮긴다
    HanoiTower(n - 1, by, from , to, answer);
}

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;
    HanoiTower(n, 1,2,3, answer);
    return answer;
}
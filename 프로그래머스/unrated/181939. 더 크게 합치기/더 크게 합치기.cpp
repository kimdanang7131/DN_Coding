#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string ab = "";
    string ba = "";
    
    ab += to_string(a);
    ab += to_string(b);
    
    ba += to_string(b);
    ba += to_string(a);
    

    
    answer = stoi(ab) >= stoi(ba) ? stoi(ab) : stoi(ba);
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int add(const int& a, const int& b)
{
    string num;
    num += to_string(a);
    num += to_string(b);

    return stoi(num);
}

int mul(const int& a, const int& b)
{
    return 2 * a * b;
}

int solution(int a, int b) {
    int answer = 0;
    
    answer = add(a, b) > mul(a, b) ? add(a, b) : mul(a, b);
    return answer;
}
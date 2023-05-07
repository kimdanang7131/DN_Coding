#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(int a, int b)
{
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;

    string temp = "";
    temp = to_string(n);

    vector<long long> order;

    for (int i = 0; i < temp.size(); i++)
    {
        order.push_back((temp[i] -'0'));
    }

    temp = "";
    sort(order.begin(), order.end(), compare);

    for (auto o : order)
    {
        temp += to_string(o);
    }

    answer = stoll(temp);

    return answer;
}
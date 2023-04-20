#include <string>
#include <vector>
#include <map>

using namespace std;

bool primeChk(const int& pnum)
{
    if (pnum <= 1)
        return false;

    for (int i = 2; i <= pnum; i++)
    {
        if (pnum / i == 1)
        {
            return true;
        }
    }

    return false;
}

vector<int> solution(int n) {
    vector<int> answer;
    map<int, int> factor;

    while (n > 1)
    {
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (primeChk(i))
            {
                if (n % i == 0)
                {
                    factor.insert({ i,i });
                    count = i;
                    break;
                }
            }
        }
        n /= count;
    }

    for (const auto& f : factor)
    {
        answer.push_back(f.second);
    }
    return answer;
}
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;

    sort(array.begin(), array.end());

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] < n)
            ++answer;
    }

    if (answer >= array.size())
    {
        answer = array.size() - 1;
    }
    else if (answer == 0)
    {
        answer = answer;
    }
    else
    {
        abs(array[answer - 1] - n) <= abs(array[answer] - n) ? answer = answer - 1 : answer = answer;
    }

    return array[answer];
}
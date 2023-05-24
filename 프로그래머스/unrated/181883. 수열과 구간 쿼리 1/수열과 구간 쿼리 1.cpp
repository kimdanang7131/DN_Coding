#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    int count = 0;

    for (const auto arr_temp : queries)
    {
            for (int i = arr_temp[0]; i <= arr_temp[1]; i++)
            {
                arr[i] += 1;
            }
        count++;
    }

    answer = arr;

    return answer;
}
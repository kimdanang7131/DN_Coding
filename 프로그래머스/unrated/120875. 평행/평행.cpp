#include <string>
#include <vector>
#include <cmath>

using namespace std;

void Normalize(float* arr)
{
    int len = sqrt(pow(arr[0], 2)) + sqrt(pow(arr[1], 2));

    arr[0] /= len;
    arr[1] /= len;
}

void SubNormalizedVector(float* arr, vector<vector<int>>& dots , int first , int last)
{
    arr[0] = dots[last][0] - dots[first][0];
    arr[1] = dots[last][1] - dots[first][1];

    Normalize(arr);
    arr[0] = abs(arr[0]);
    arr[1] = abs(arr[1]);

}

bool cmp(const float* arr1, const float* arr2)
{
    return (arr1[0] == arr2[0] && arr1[1] == arr2[1]);
}


int solution(vector<vector<int>> dots) {
    int answer = 0;

    float ab[2];
    float ac[2];
    float ad[2];

    float bd[2];
    float bc[2];
    float cd[2];

    SubNormalizedVector(ab, dots, 0, 1);
    SubNormalizedVector(ac, dots, 0, 2);
    SubNormalizedVector(ad, dots, 0, 3);

    SubNormalizedVector(bc, dots, 1, 2);
    SubNormalizedVector(bd, dots, 1, 3);
    SubNormalizedVector(cd, dots, 2, 3);

    if (cmp(ab, cd)) return true;
    if (cmp(ac, bd)) return true;
    if (cmp(ad, bc)) return true;

    return answer;
}

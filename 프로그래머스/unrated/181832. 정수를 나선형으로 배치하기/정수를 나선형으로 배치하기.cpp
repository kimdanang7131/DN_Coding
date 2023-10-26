#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));

    int count = 1;

    int xCount = n;
    int yCount = n - 1;

    int xPos = 0;
    int yPos = 0;

    int dir = 1;
    for (int cycle = 0; cycle < n; cycle++)
    {
        if (cycle % 2 == 0 || cycle == 0) // 짝수
            dir = 1;
        else
            dir = -1;

        for (int x = 0; x < xCount; x++)
        {
            answer[yPos][xPos] = count++;
            xPos += dir;
        }

        if (dir == 1)
        {
            xPos -= 1;
            yPos += 1;
        }
        else
        {
            xPos += 1;
            yPos -= 1;
        }

        for (int y = 0; y < yCount; y++)
        {
            answer[yPos][xPos] = count++;
            yPos += dir;
        }

        if (dir == 1)
        {
            xPos -= 1;
            yPos -= 1;
        }
        else
        {
            xPos += 1;
            yPos += 1;
        }

        xCount -= 1;
        yCount -= 1;
    }

    return answer;
}

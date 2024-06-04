#include <iostream>
#include <vector>
#include <map>

using namespace std;

float ans;

int main()
{
	int n = 20;

	map<string, float> scoreMap;
	scoreMap["A+"] = 4.5f; scoreMap["A0"] = 4.0f;
	scoreMap["B+"] = 3.5f; scoreMap["B0"] = 3.0f;
	scoreMap["C+"] = 2.5f; scoreMap["C0"] = 2.0f;
	scoreMap["D+"] = 1.5f; scoreMap["D0"] = 1.0f;
	scoreMap["F"]  = 0.f;

	float sum = 0;
	float scoSum = 0;
	while (n--)
	{
		string name;
		float num;
		string score;

		cin >> name >> num >> score;

		

		if (score == "P")
		{
			num = 0.f;
			score = 0.f;
		}

		scoSum += num;
		sum += num * scoreMap[score];
	}

	ans = sum / scoSum;

	cout << ans << endl;
	return 0;
}
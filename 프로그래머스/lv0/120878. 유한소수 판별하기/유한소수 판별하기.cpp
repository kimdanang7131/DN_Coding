#include <string>
#include <vector>
#include <map>
#include <algorithm>

	using namespace std;

	int solution(int a, int b) {
		int answer = 0;
		map<int, int> m;

		for (int i = 1; i <= a; i++)
		{
			if (a % i == 0)
				m[i] += 1;
		}
		for (int i = 1; i <= b; i++)
		{
			if (b % i == 0)
				m[i] += 1;
		}
		int big = 0;

		for (const auto& i : m)
		{
			if (i.second >= 2)
			{
				if (big < i.first)
					big = i.first;
			}
		}

		if (big != 1)
		{
			while (1)
			{
				if ((b % big) != 0 || (a % big) != 0)
					break;
				a /= big;
				b /= big;
			}
		}

		m.clear();


		if (b == 1 || a % b == 0)
		{
			return 1;
		}


		for (int i = 1; i <= b; i++)
		{
			if (b % i == 0)
			{
				m[i] += 1;
			}

		}


		for (auto i : m)
		{

			if (i.first >= 2)
			{
				bool chk = false;

				for (int a = 2; a < i.first; a++)
				{
					if (i.first % a == 0)
					{
						chk = true;
					}

					if (i.first % 3 == 0)
						return 2;
				}
				if (!chk)
				{
					if (i.first == 2 || i.first == 5)
						answer = 1;
					else
						return 2;
				}
			}
		}
		return answer;
	}
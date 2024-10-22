#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<string> recordVec; 

void HanoiTower(int count, int from , int by , int to)
{
	if(count == 1)
	{
		cnt++;
		recordVec.push_back(to_string(from) + " " + to_string(to));
	}
	else
	{
		HanoiTower(count - 1, from, to , by);
		recordVec.push_back(to_string(from) + " " + to_string(to));
		cnt++;
		HanoiTower(count - 1, by, from , to);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	HanoiTower(n, 1, 2, 3);
	
	cout << cnt << endl;
	for(int i=0; i < recordVec.size(); i++)
	{
		cout << recordVec[i] << '\n';
	}
}

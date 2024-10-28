#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'


int n;
int sum = 987654321;
vector<vector<int>> boardVec;
vector<bool> visitVec; 


// n은 짝수 ,  n /2 명으로 이루저잊ㄴ 스타틈 과과 링크 팀으로 나눠야한다
// 1 ~ N 까지 배정
// i,j가 같은 팀일때 플러스 능력치  


void CaculateScore(const int& teamCnt ,int start, vector<int> teamA)
{
	if(teamCnt == (n / 2))
	{
		vector<int> teamB;
		int tempA = 0;
		int tempB = 0;
		
		for(int i=0; i < n; i++)
		{
			if(!visitVec[i])
				teamB.push_back(i);
		}
		
		for(int i = 0; i < teamA.size(); i++)
		{
			for(int j = i + 1; j < teamA.size(); j++)
			{
				tempA += boardVec[teamA[i]][teamA[j]] + boardVec[teamA[j]][teamA[i]];
			}
		}
		
		for(int i = 0; i < teamB.size(); i++)
		{
			for(int j = i + 1; j < teamB.size(); j++)
				tempB += boardVec[teamB[i]][teamB[j]] + boardVec[teamB[j]][teamB[i]];
		}
		
		sum = min(sum, abs(tempA - tempB));
		return;
	}
	
	for (int i = start; i < n; i++)
	{
		if(!visitVec[i])
		{
			visitVec[i] = true;
			teamA.push_back(i);
			CaculateScore(teamCnt + 1, i + 1, teamA);
			teamA.pop_back();
			visitVec[i] = false;
		}
	}
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> n;
	boardVec.resize(n, vector<int>(n));
	visitVec.resize(n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> boardVec[i][j];
		}
	}
	vector<int> teamA;
	CaculateScore(0 , 0, teamA);
	
	cout << sum << endl;
	
	return 0;
}


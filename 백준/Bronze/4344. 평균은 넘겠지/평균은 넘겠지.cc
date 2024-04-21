#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int cnt;
		cin >> cnt;
		
		vector<int> scoreVec(cnt,0);
		
		int sum = 0;
		for(int j = 0; j < cnt; j++)
		{
			cin >> scoreVec[j];
			sum += scoreVec[j];
		}
		
		double avg;
		avg = (double)(sum) / cnt;
		
		int overCnt = 0;
		for(int k=0; k < scoreVec.size(); k++)
		{
			if(scoreVec[k] > avg)
			overCnt++;
		}
		
		double ret = (double)(overCnt) / cnt * 100.f;
		
		printf("%.3lf%%\n",ret);
	}
	
	
    return 0;
}
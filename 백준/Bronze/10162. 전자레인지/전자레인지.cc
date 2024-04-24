#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	vector<int> buttonVec{ 300 , 60 ,10 };
	vector<int> answerVec(3,0);
	
	int cnt = 0;
	bool check = false;
	while(n > 0)
	{
		if(cnt >= buttonVec.size())
		{
			check = true;
			break;
		}
		
		answerVec[cnt] = n / buttonVec[cnt];
		n %= buttonVec[cnt++];
	}
	
	if(check)
	{
		cout << "-1";
		return 0;
	}
		
	for(int i=0; i<answerVec.size(); i++)
		cout << answerVec[i] << " ";
		
	return 0;
}
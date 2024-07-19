#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<int> cardVec;

int dfs(int index, int curSum, int cnt)
{
    if (cnt == 3)
    {
        return curSum;
    }

    int maxSum = 0;
    for (int i = index; i < cardVec.size(); i++)
    {
        if (curSum + cardVec[i] <= m)
        {
            maxSum = max(maxSum, dfs(i + 1, curSum + cardVec[i], cnt + 1));
        }
    }

    return maxSum;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	int sum = 0;
	
	while(n--)
	{
		int a; 
		cin >> a;
		
		cardVec.push_back(a);
	}
	
	int ans = 0;
	ans = dfs(0, 0 , 0);
	
	cout << ans << endl;
	return 0;
}
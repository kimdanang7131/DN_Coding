#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX_SIZE 100000+1

int n,k;
int ret;

bool visited[MAX_SIZE];

void bfs() 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, n});
    
    visited[n] = true;
    
    while (!q.empty()) {
        int time = q.top().first;
        int now = q.top().second;
        q.pop();
        
        if (now == k) {
            ret = time;
            return;
        }
        
        if (now * 2 < MAX_SIZE && !visited[now * 2]) {
            visited[now * 2] = true;
            q.push({time, now * 2});
        }
        
        if (now + 1 < MAX_SIZE && !visited[now + 1]) {
            visited[now + 1] = true;
            q.push({time + 1, now + 1});
        }
        
        if (now - 1 >= 0 && !visited[now - 1]) {
            visited[now - 1] = true;
            q.push({time + 1, now - 1});
        }
    }
}
int main()
{	
	cin >> n >> k;
	bfs();
	
	cout << ret << endl;
	
	return 0;
}
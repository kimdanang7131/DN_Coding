#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

typedef pair<int,int> Pos;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int  n, m, input;
    cin >> n;
    
    deque<int> sq;
    
    vector<int> queVec(n);
    for(int i=0; i<n; i++)
    	cin >> queVec[i];
        
    for(int i=0; i<n; i++) 
	{
        cin >> input;
        if(queVec[i] == 0)  // Queue
            sq.push_front(input);
    }
            
    cin >> m;
    for(int i=0; i<m; i++)
	{
        cin >> input;
        sq.push_back(input);
        cout << sq.front() << ' ';
        sq.pop_front();
    }
	 

	return 0;
}

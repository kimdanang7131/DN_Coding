#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n , m;
vector<class Edge> v;
vector<int> parentVec;


int GetParent(vector<int>& parent, int x)
{
	if(parent[x] == x)
		return x;
	else
		return parent[x] = GetParent(parent, parent[x]);
}

void UnionParent(vector<int>& parent, int a, int b)
{
	a = GetParent(parent,a);
	b = GetParent(parent,b);
	
	if(a < b) parent[b] = a;
	else      parent[a] = b;
}

int FindParent(vector<int>& parent, int a, int b)
{
	a = GetParent(parent,a);
	b = GetParent(parent,b);
	
	if(a == b) return 1;
	else       return 0;
}

class Edge
{
	public:
		int node[2];
		int distance;
		Edge(int a,int b, int distance)
		{
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		
		bool operator<(Edge& edge)
		{
			return this->distance < edge.distance;
		}
};



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int v1,v2,w;
		
		cin >> v1 >> v2 >> w;
		
		v.emplace_back(v1,v2,w);
	}
	
	sort(v.begin(),v.end());
	
	parentVec.resize(n + 1);
	for(int i=0; i<n; i++)
	{
		parentVec[i] = i;
	}
	
	int sum = 0;

	for(int i = 0; i<v.size(); i++)
	{
		if(!FindParent(parentVec, v[i].node[0] , v[i].node[1]))
		{
			sum += v[i].distance;
			UnionParent(parentVec,v[i].node[0], v[i].node[1]);
		}
	}
	
	cout << sum << endl;

	return 0;
}
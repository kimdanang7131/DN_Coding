#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    unordered_set<int> s;

    for (int i = 0; i < n + m; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) 
            s.erase(x);
		else
            s.insert(x);
    }

    cout << s.size();

    return 0;
}

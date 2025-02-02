#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int k;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    vector<long long> v(k); 
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    long long maxNum = *max_element(v.begin(), v.end()); 
    long long pl = 1; 
    long long pr = maxNum; 
    long long mid; 

    long long ans = 0;

    while (pl <= pr)
    {
        mid = (pl + pr) / 2;
        long long sum = 0; 

        for (int i = 0; i < v.size(); i++)
        {
            sum += (v[i] / mid);
        }

        if (sum >= n) 
        {
            ans = mid;
            pl = mid + 1; 
        }
        else if (sum < n)
        {
            pr = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
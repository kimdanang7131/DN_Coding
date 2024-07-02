#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long ans = 0;
    
    sort(weights.begin(), weights.end());
    
    map<int,long long> mp;
    for(int i=0; i<weights.size(); i++)
    {
        mp[weights[i]]++;
    }
    
    for(const pair<int,int>& p : mp)
    {
        long long n = p.second;
        if(n > 1)
            ans += n * (n - 1) / 2;
    }
    
    weights.erase(unique(weights.begin(), weights.end()), weights.end());
    
    for(int i=0; i< weights.size(); i++)
    {
        int w2 = weights[i] * 2;
        
        if(w2 % 3 == 0)
            ans += mp[w2 / 3] * mp[weights[i]];
        if(w2 % 4 == 0)
            ans += mp[w2 / 4] * mp[weights[i]];
        
        int w3 = weights[i] * 3;
        if(w3 % 4 == 0)
            ans += mp[w3/4] * mp[weights[i]];
    }
 
    
    return ans;
}
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
    if(a.second == b.second)
        return a.first > b.first;
    
    return a.second < b.second;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    map<int,int> temp;
    
    sort(numlist.begin(), numlist.end());
    
    for(int i=0; i<numlist.size(); i++)
    {
        temp.insert({i,abs(n-numlist[i])});
    }
    
    vector<pair<int,int>> vec(temp.begin(), temp.end());
    sort(vec.begin(),vec.end(), cmp);
    
    for(auto num : vec)
    {
        answer.push_back(numlist[num.first]);
    }

    return answer;
}
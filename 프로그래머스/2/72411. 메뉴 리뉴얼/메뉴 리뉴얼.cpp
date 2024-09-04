#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> strMap;

bool cmp(const pair<string,int>& p1, const pair<string,int>& p2)
{
    return p1.second > p2.second;
}

void DFS(const string& order, string comb, int index, int depth)
{
    if(depth == comb.length())
    {
        strMap[comb]++;
        return;
    }
    
    for(int i = index; i < order.length(); i++)
    {
        comb[depth] = order[i];
        DFS(order, comb , i + 1, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i<orders.size(); i++)
    {
        sort(orders[i].begin() , orders[i].end());
        for(int j=0; j < course.size(); j++)
        {
            string comb = "";
            comb.resize(course[j]);
            DFS(orders[i],comb,0,0);
        }
    }
    
    vector<pair<string,int>> sorted;
    for(const pair<string,int>& order : strMap)
    {
        if(order.second > 1)
            sorted.push_back({order.first , order.second});
    }
    
    sort(sorted.begin() , sorted.end() , cmp);
    
    for(int i=0; i<course.size(); i++)
    {
        int max = 0;
        for(int j=0; j<sorted.size(); j++)
        {
            if(sorted[j].first.length() != course[i])
            {
                continue;
            }
            else if(max == 0)
            {
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            }
            else if(max == sorted[j].second)
                answer.push_back(sorted[j].first);
            else
                break;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
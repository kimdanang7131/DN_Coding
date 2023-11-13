#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool customCmp(const pair<string, char>& a , const pair<string, char>& b)
{
    if( a.second == b.second)
    {
        int minLength = min(a.first.size() , b.first.size());
        
        for(int i =0; i < minLength; i++)
        {
            if(a.first[i] < b.first[i])
            {
                return true;
            }
            else if(a.first[i] > b.first[i])
            {
                return false;
            }
        }
        
        if(minLength == a.first.size())
            return true;
        else
            return false;
    }
    
    return a.second < b.second;
}


vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<pair<string , char>> temp;    
    
    for(int i = 0; i < strings.size(); i++)
    {
        temp.emplace_back( strings[i] ,strings[i][n] );
    }
    
    sort(temp.begin() , temp.end() , customCmp);
    
    for(int i=0; i<strings.size(); i++)
    {
        answer.push_back(temp[i].first);
    }
    
    return answer;
}
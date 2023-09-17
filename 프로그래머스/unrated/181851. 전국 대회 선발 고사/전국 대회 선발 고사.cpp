#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    map<int,int> temp;
    
    for(int i=0; i<rank.size(); i++)
    {
        if(attendance[i])
        {
            temp.insert({rank[i],i});
        }
    }
    
    vector<int> place;
    
    for(auto i : temp)
    {
        place.push_back(i.second);
    
        if(place.size() >=3)
            break;
    }
    
    for(auto i: place)
    {
        cout<< i << endl;
    }
    
    answer = (10000 * place[0]) + (100 * place[1]) + place[2];
    
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬한 데이터들이 담긴 이차원 정수 리스트 data
// 어떤 정보를 기준으로 데이터를 뽑아낼지를 의미하는 문자열 ext
// 뽑아낼 정보의 기준값을 나타내는 정수 val_ext
// 정보를 정렬할 기준이 되는 문자열 sort_by

// 2000 ~ 3000


bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
    return a.second < b.second;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    vector<pair<string,int>> stdVec;
    stdVec.push_back({"code"    , 0});
    stdVec.push_back({"date"    , 1});
    stdVec.push_back({"maximum" , 2});
    stdVec.push_back({"remain"  , 3});
    
    int choice = -1;
    int sortChoice = -1;
    for(int i=0; i < 4; i++)
    {
        if(stdVec[i].first == ext)
            choice = stdVec[i].second;
        
        if(stdVec[i].first == sort_by)
            sortChoice = stdVec[i].second;
    }
    
    vector<pair<int,int>> orderVec;
    
    for(int i = 0; i < data.size(); i++)
    {      
        if(data[i][choice] < val_ext)
            orderVec.push_back({ i , data[i][sortChoice]});
    }
    
    sort(orderVec.begin() , orderVec.end() , cmp);
    
    
    for(int i=0; i < orderVec.size(); i++)
    {
        int dataRow = orderVec[i].first;
        
        answer.push_back(data[dataRow]);
    }
    
    
    
    return answer;
}
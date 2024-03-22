#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

// result : 처리 결과 메일 받은 횟수
// muzi frodo
// apeach frodo
// frodo neo
// muzi neo
// apeach muzi


//                       이용자 ID          /      신고한 이용자의 ID /  정지 기준 신고 횟수
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size() , 0);
    
    int size = id_list.size();
    map<string,set<string>> reporters;
    
    for(int i=0; i < size; i++)
        reporters[id_list[i]];
    
    for(int i=0; i<report.size(); i++)
    {
        int idx = report[i].find(' ');
        string reporter = report[i].substr(0,idx);
        string reported = report[i].substr(idx + 1);
        
        reporters[reporter].insert(reported);
    }
    
    map<string,int> reportedMap;
    vector<string> stopName;
    
    for(auto m : reporters)
    {
        for(auto str : m.second)
        {
            reportedMap[str] += 1;           
        }
    }
    
    for(auto m : reportedMap)
    {
        if(m.second >= k)
            stopName.push_back(m.first);
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        string name = id_list[i];
        
        for(int j=0; j< stopName.size(); j++)
        {
            if(reporters[name].find(stopName[j]) != reporters[name].end())
                answer[i] += 1;
        }
    }
    return answer;
}
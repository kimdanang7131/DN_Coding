#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;


// fees   : 기본 시간 / 기본 요금 / 단위 시간 / 단위 요금
// record : 시각 (00:00 ~ 23:59) / 차량 번호 / 내역 ( In, Out)
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer; 
    
    map<string, pair<int,int>> historyMap;
    map<string, int> resultMap;
    stringstream ss;
    
    for(int i=0; i<records.size(); i++)
    {
        records[i][2] = ' ';
        
        ss.clear();
        ss.str(records[i]);
        
        int h = 0;
        int m = 0;
        string carNum = "";
        string history = "";
        string temp = "";
        
        ss >> temp;
        h = stoi(temp);
        temp = "";
        
        ss >> temp;
        m = stoi(temp);
        temp = "";
        
        ss >> carNum;
        ss >> history;
        
        if(historyMap.count(carNum) <= 0)
        {
            historyMap[carNum] = { h, m };
            continue;
        }
        
        int prevH = historyMap[carNum].first;
        int prevM = historyMap[carNum].second;
        
        int newH = 0;
        int newM = 0;
        
        newH += (h - prevH) * 60;
        newM += (m - prevM);
        int ret = newH + newM;
        
        resultMap[carNum] += ret;
        historyMap.erase(carNum);
        
    }
    
    for(auto& m : historyMap)
    {
        int prevH = m.second.first;
        int prevM = m.second.second;
        
        int newH = 0;
        int newM = 0;
        
        newH += (23 - prevH) * 60;
        newM += (59 - prevM);
        int ret = newH + newM;
        
        resultMap[m.first] += ret;
    }
    
    int baseMin = fees[0];
    int baseFee = fees[1];
    int unitMin = fees[2];
    int unitFee = fees[3];
    
    for(auto& m : resultMap)
    {
        int ret = baseFee;
        
        if(m.second > baseMin)
        {
            double temp = (double)( m.second - baseMin ) / unitMin;
            
            // 정수가 아니면
            if(temp - (int)temp != 0)
                temp += 1;
         
           ret += (int)temp * unitFee;
        }
        
        answer.push_back(ret);
    }
    return answer;
}
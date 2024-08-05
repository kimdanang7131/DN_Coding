#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string convertMelody(const string& melody) 
{
    string result;
    for (int i = 0; i < melody.length(); ++i) 
    {
        if (i + 1 < melody.length() && melody[i + 1] == '#') {
            result += tolower(melody[i]);
            ++i;
        } 
        else 
        {
            result += melody[i];
        }
    }
    return result;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    m = convertMelody(m);
    
    vector<vector<string>> infoVec;
    for(int i=0; i < musicinfos.size(); i++)
    {
        stringstream ss;
        ss.str(musicinfos[i]);
        
        string start, end, title, melody;

        getline(ss, start , ',');
        getline(ss, end   , ',');
        getline(ss, title , ',');
        getline(ss, melody, ',');
        
        vector<string> tempVec;
        tempVec.push_back(start);
        tempVec.push_back(end);
        tempVec.push_back(title);
        tempVec.push_back(melody);
        
        infoVec.push_back(tempVec);
    }
    
    
    int longestTime  = 0;
    
    for(int i=0; i<infoVec.size(); i++)
    {
        int start = stoi(infoVec[i][0].substr(0,2)) * 60 + stoi(infoVec[i][0].substr(3,2));
        int end   = stoi(infoVec[i][1].substr(0,2)) * 60 + stoi(infoVec[i][1].substr(3,2));
        int playTime  = end - start;
        
        string title  = infoVec[i][2];
        string melody = convertMelody(infoVec[i][3]);
        
        string newStr;
        for(int j = 0; j < playTime; j++)
        {
            newStr += melody[j % melody.size()];
        }
        
        if(newStr.find(m) != string::npos)
        {
            if(longestTime < playTime)
            {
                longestTime = playTime;
                answer = title;
            }
        }
    }
    
    return answer;
}
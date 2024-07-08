#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> dQ;

void Insert(const string& s)
{
    int n = stoi(s);
    
    dQ.push_back(n);
    sort(dQ.begin(), dQ.end());
}

void Delete(const string& s)
{
    if(s == "1")
    {
        if(!dQ.empty())
            dQ.pop_back();
    }
    else if(s == "-1")
    {
        if(!dQ.empty())
            dQ.pop_front();
    }
    else
    {
        int n = stoi(s);
        
        for(auto iter = dQ.begin(); iter != dQ.end(); iter++)
        {
            if(*iter == n)
            {
                dQ.erase(iter);
                break;
            }
        }
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i=0; i<operations.size(); i++)
    {
        stringstream ss;
        ss.str(operations[i]);
        
        string temp;
        vector<string> strVec;
        while(ss >> temp)
        {
            strVec.push_back(temp);
        }
        
        string c  = strVec[0];
        string s  = strVec[1];
            
        if(c == "I")
        {
            Insert(s);
        }
        else if(c == "D")
        {
            Delete(s);
        }
    }
    
    if(dQ.empty())
    {
        answer = {0,0};
    }
    else
    {
        answer = {dQ.back(), dQ.front()};
    }
    
    return answer;
}
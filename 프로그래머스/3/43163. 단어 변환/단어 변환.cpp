#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int,int> idxMap;

int bfs(string begin , string target , vector<string> words)
{
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    int wordSize = words[0].size();
    
    while(!q.empty())
    {
        string str = q.front().first;
        int cnt    = q.front().second;
    
        q.pop();
        
        if(str == target)
        {
            return cnt;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            if(idxMap.count(i) > 0)
                continue;
            
            string word = words[i];
            int check =  0;
        
            for(int j = 0; j < word.size(); j++)
            {      
                if(str[j] != word[j])
                    check++;
            }
            
            if(check == 1)
            {
                idxMap[i] = 1;
                q.push({word , cnt + 1});
            }
              
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    answer = bfs(begin, target, words);
    return answer;
}
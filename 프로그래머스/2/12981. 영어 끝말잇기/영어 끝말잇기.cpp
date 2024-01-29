#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int number  = 1;
    int count   = 1;
    unordered_set<string> dedupeSet;
    dedupeSet.insert(words[0]);
    
    bool check = false;
    for(int i = 1; i < words.size(); i++)
    {
        number = (i % n) + 1;
        count  = (i / n) + 1;
        
        int prevLastChar = words[i - 1].back();
        
        if(prevLastChar != words[i].front() || dedupeSet.find(words[i]) != dedupeSet.end())
        {
            check = true;
            break;
        }
        
        dedupeSet.insert(words[i]);
    }   
    
    if(check)
    {
        answer.push_back(number);
        answer.push_back(count);
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
   

    return answer;
}
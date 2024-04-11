#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> checkSet;
    
    
    
    for(int i = 0; i < skill_trees.size(); i++)
    {
        bool check = true;
        string temp = skill;
        
        for(int k = 0; k < skill.size(); k++)
           checkSet.insert(skill[k]);
        
        for(int j = 0; j < skill_trees[i].size(); j++)
        {
            char c = temp.front();
            
            if(checkSet.find(c) != checkSet.end())
               checkSet.erase(c);
            
            if(c == skill_trees[i][j])
            {
                check = true;
                temp.erase(0,1);
            } 
            else if(checkSet.find(skill_trees[i][j]) != checkSet.end())
            {
                check = false;
                break;
            }
        }
        
        if(check)
            ++answer;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    
    map<int,int> space;
    vector<string> coll;
    
    int count=0;
    bool isSpace=false;
    
    string temp = "";
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            if(temp.size())
            {
                coll.push_back(temp);
                temp="";
            }
            
            if(!space.count(count))
                space.insert({count,1});
            else
                space[count]+=1;  
            
            isSpace=true;
        }
        else
        {
            if(isSpace)
                ++count;
            
            isSpace=false;
            
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            
            temp+=s[i];
        }    
    }
    
    if(temp.size())
    {
       coll.push_back(temp);
       temp="";
    }  
    
    int index=0;
    
    for(auto& str : coll)
    {
        if(isalpha(str[0]))
            str[0] = toupper(str[0]);
        
        answer+=str;
        if(space.count(index))
        {
            for(int i=0; i<space[index]; i++)
            {
                answer +=' ';
            }
            ++index;
        }
    }
    
    
    return answer;
}
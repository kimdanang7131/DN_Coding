#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    string temp = "";
    // 1, 2단계
    for(int i=0; i < new_id.size(); i++)
    {
        char c = new_id[i];
        
        if(!isalpha(c) && !isdigit(c) && c != '-' && c != '_' && c != '.')
            continue;
        else
        {
            if(isupper(c))
               temp += tolower(c);
            else
                temp += c;
        }
    }
    
    // 3단계
    string newString = "";
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] == '.')
        {
            if(newString.back() == '.')
                continue;
        }
        newString += temp[i];
    }
    
    // 4단계
    if(newString.front() == '.')
        newString.erase(newString.begin());
    
    if(newString.back() == '.')
        newString.erase(newString.end() - 1);
    
    // 5단계
    if(newString.empty())
        newString += "a";
    
    // 6단계
    if(newString.length() >= 16)
        newString.erase(newString.begin() + 15 , newString.end());
    if(newString.back() == '.')
        newString.erase(newString.end() - 1 , newString.end());
    
    // 7단계
    while(newString.length() <= 2)
    {
        newString += newString.back();
    }
   
    answer = newString;
    
    return answer;
}
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string lower(string str)
{
    for(int i=0; i<str.size(); i++)
    {
       str[i] = tolower(str[i]);
    }
    return str;
}

string upper(string str)
{
    for(int i=0; i<str.size(); i++)
    {
       str[i] = toupper(str[i]);
    }
    return str;
}


vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    string (*converter)(string);
    
    for(int i=0; i<strArr.size(); i++)
    {
        if(i % 2 == 0)
            converter = lower;
        else
            converter = upper;
        
        answer.push_back(converter(strArr[i]));
    }
    return answer;
}
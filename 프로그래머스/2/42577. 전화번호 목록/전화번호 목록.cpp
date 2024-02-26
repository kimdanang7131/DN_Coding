#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    if(phone_book.size() == 1)
        return true;
    
    set<string> checkSet;
    
    for(int i=0; i<phone_book.size(); i++)
        checkSet.insert(phone_book[i]);
    
    for(int i=0; i<phone_book.size(); i++)
    {
        string temp = "";
        
        for(int j=0; j<phone_book[i].size(); j++)
        {
            temp += phone_book[i][j];
            
            if(checkSet.find(temp) != checkSet.end() && temp != phone_book[i])
                return false;
        }
    }

    
    return answer;
}
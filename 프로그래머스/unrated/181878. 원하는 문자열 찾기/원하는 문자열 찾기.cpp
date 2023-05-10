#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {

    for(auto& c : myString)
        c= tolower(c);
    
    for(auto& c : pat)
        c = tolower(c);
    
    return myString.find(pat) != string::npos;
}
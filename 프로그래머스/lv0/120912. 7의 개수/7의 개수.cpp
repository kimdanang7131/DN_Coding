#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    string seven;
    for(int i=0; i<array.size(); i++)
    {
        seven+=to_string(array[i]);
    }
    
    for(int i=0; i<seven.size(); i++)
    {
        if(seven[i] == '7')
            ++answer;
    }
    return answer;
}
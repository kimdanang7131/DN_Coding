#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a , const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    int N = numbers.size();
    
    vector<string> strings;
    for(int i=0; i<N; i++)
    {
        strings.push_back(to_string(numbers[i]));
    }
    
    sort(strings.begin(), strings.end() ,cmp);
    
    for(int i=0; i<N; i++)
    {
        answer+= strings[i];
    }
    
    if(answer[0] == '0')
        answer = '0';

    return answer;
}
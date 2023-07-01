#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    
    for(auto& query : queries)
    {
        for(int i = 0; i < ( query[1] - query[0] + 1 ) / 2; i++)
        {           
            char temp                =  my_string[query[1] - i];
            my_string[query[1] - i]  =  my_string[query[0] + i];
            my_string[query[0] + i]  =  temp;
        }
    }
    answer = my_string;
    return answer;
}
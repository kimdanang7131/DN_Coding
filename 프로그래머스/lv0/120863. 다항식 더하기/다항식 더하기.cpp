#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    
    for(int i=0; i<polynomial.size(); i++)
    {
        if(polynomial[i] == '+')
            polynomial[i] = ' ';
    }
    
    stringstream ss;
    ss.str(polynomial);
    
    vector<string> formula;
    
    while(ss >> answer)
    {
        formula.push_back(answer);
    }
    
    bool has_x;
    
    
    int num_result = 0;
    vector<string> temp;
    
    for(auto str : formula)
    {
        if(str.find('x') != string::npos)
        {
            temp.push_back(str);
        }
        else
            num_result += stoi(str);
    }

    int x_result =0;
    
    for(auto str : temp)
    {
        if(str.size() == 1)
            x_result += 1;
        else
        {
            string tmp;
            for(int i=0; i<str.find('x'); i++)
            {
                tmp += str[i];
            }
            x_result += stoi(tmp);
        }
    }
    
    answer.clear();
    
 
    
    if( num_result != 0 && x_result != 0)
    {
        if(x_result == 1)
              answer = "x + " + to_string(num_result);
        else
            answer = to_string(x_result) + "x + " + to_string(num_result);
    }
       
    else
    {
        if( x_result != 0)
        {
            if(x_result == 1)
               answer = "x";
            else
               answer = to_string(x_result) + "x";
        }
           
        else if( num_result != 0 )
           answer = to_string(num_result);
    }
    
    
    
    return answer;
}
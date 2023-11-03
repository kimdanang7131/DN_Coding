#include <string>
#include <vector>
#include <stack>

using namespace std;

string convertTobinary(int decimal , int size)
{
    stack<int> binary;
    
    while(decimal != 0)
    {
        int r = decimal % 2;
        binary.push(r);
        
        decimal /= 2;
    }
    
    while(binary.size() < size)
    {
          binary.push(0);
    }
    
    string temp;
    
    while(!binary.empty())
    {
        temp += binary.top() + '0';
        binary.pop();
    }

    
    return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<vector<int>> secretMap1(n , vector<int>(n, 0));
    vector<vector<int>> secretMap2(n , vector<int>(n, 0));
    
    for(int i=0; i < n; i++)
    {
        string temp1 = convertTobinary(arr1[i] , n);
        string temp2 = convertTobinary(arr2[i] , n);
        
        for(int j=0; j < n; j++)
        {
           secretMap1[i][j] = temp1[j] - '0';
           secretMap2[i][j] = temp2[j] - '0';
            
        }
    }
       
    for(int i=0; i<n; i++)
    {
        string temp;
        int mapNum = 0;
        
        for(int j=0; j < n; j++)
        {
            mapNum = secretMap1[i][j] + secretMap2[i][j];  
            
            if(mapNum > 0)
                temp += "#";
            else
                temp += " ";
        }    
        answer.push_back(temp);
    }

    return answer;
}
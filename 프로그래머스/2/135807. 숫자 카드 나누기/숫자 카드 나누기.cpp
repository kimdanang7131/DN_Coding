#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd(int a , int b)
{
    while (b != 0) 
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    
    return a;
}

bool CheckPassed(int divi, const vector<int>& array)
{
    for (const int& num : array) 
    {
        if (num % divi == 0) 
             return false;
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) 
{
    int answer = 0;
    int size = arrayA.size();
    
    int gcd_A = arrayA[0];
    int gcd_B = arrayB[0];
    
    for(int i = 1; i < size; i++)
    {
       gcd_A = gcd(gcd_A, arrayA[i]); 
       gcd_B = gcd(gcd_B, arrayB[i]);
    }

    int max_a = CheckPassed(gcd_A, arrayB) ? gcd_A : 0;
    int max_b = CheckPassed(gcd_B, arrayA) ? gcd_B : 0;
    
    return max(max_a, max_b);
}
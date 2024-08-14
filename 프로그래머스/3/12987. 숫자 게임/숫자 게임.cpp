#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int aIdx = 0;
    int bIdx = 0;
    
    while(aIdx < A.size() && bIdx < B.size())
    {
        if(B[bIdx] > A[aIdx])
        {
            answer++;
            aIdx++;
            bIdx++;
        }
        else
        {
            bIdx++;
        }
    }
    
    
    return answer;
}
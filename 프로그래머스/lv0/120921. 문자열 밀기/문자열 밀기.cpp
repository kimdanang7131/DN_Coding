#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    for(int i=0; i<A.length(); i++)
    {
        if(A == B)
            return i;
        else
        {
            char last = A[A.length()-1];
            
            for(int j=A.length()-1; j>0; j--)
            {
                char temp = A[j];
                A[j] = A[j-1];
            }
            
            A[0] = last;
        }
    }
    return -1;
}
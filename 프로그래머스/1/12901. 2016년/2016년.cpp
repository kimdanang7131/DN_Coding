#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<int> monthDay =  { 31, 29 , 31, 30, 31 ,30,
                              31, 31 , 30, 31, 30, 31};
    
    int sum = 0;
    
    for(int i=0; i < a - 1; i++)
        sum += monthDay[i];
    
    sum += b - 1;
    int day = (sum % 7); 
   
    const char* days[] = { "FRI" , "SAT" ,"SUN" ,"MON", "TUE" , "WED" , "THU" };
    
    return days[day];
}
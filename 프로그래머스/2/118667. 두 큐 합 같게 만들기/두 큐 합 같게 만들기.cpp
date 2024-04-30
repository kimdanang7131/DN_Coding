#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0;
    queue<int> temp1;
    queue<int> temp2;
    long long sum=0, q1_sum=0, q2_sum=0;
    long long max = -1;

    for(int i=0; i<queue1.size();i++){
        sum = sum+ queue1[i] + queue2[i];
        temp1.push(queue1[i]);
        temp2.push(queue2[i]);
        q1_sum += queue1[i];
        q2_sum += queue2[i];
        if(queue1[i] > max) max = queue1[i];
        if(queue2[i] > max) max = queue2[i];
    }


    if(max > (sum/2)) return -1;

    while(!temp1.empty() | !temp2.empty()){
        if(q1_sum == q2_sum) return answer;
        if(answer > queue1.size()*5) return -1;
        if(q1_sum > q2_sum){
            int numf = temp1.front();
            temp2.push(numf);
            q2_sum += numf;
            q1_sum -= numf;
            temp1.pop();
       }
        else{
            long numf = temp2.front();
            temp1.push(numf);
            q1_sum += numf;
            q2_sum -= numf;
            temp2.pop(); 
        }
        answer++;   
    }
    return -1;
}
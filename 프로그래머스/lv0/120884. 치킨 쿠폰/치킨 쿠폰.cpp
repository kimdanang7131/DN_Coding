#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int solution(int chicken) {
    int answer = 0;

    int remain = 0;

    int one = 0;

    do
    {
        while (chicken >= 10)
        {
            answer += chicken / 10;
            remain += chicken % 10;

            chicken /= 10;
            one = chicken;
        }

        one += remain;
        remain = 0;
        chicken = one;
    } while (chicken >= 10);

    return answer;
}
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long DecToBin(long long bin)
{
    long long Dec = 0;

    for (long long i = 1; bin >= 1; i *= 10)
    {
        Dec = (bin % 2) * i + Dec;
        bin /= 2;
    }
    return Dec;
}

int BinToDec(int dec)
{
    int bin = 0;

    for (int i = 0; dec >= 1; i++)
    {
        bin += (dec % 10) * pow(2, i);
        dec /= 10;
    }

    return bin;
}


string solution(string bin1, string bin2) {
    string answer = "";

    int DecTemp1, DecTemp2;
    DecTemp1 = DecTemp2 = 0;
    int sum = 0;

    DecTemp1 = BinToDec(stoi(bin1));
    DecTemp2 = BinToDec(stoi(bin2));

    sum = DecTemp1 + DecTemp2;

    answer = std::to_string(DecToBin(sum));

    return answer;
}

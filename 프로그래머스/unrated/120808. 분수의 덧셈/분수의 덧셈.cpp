#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    vector<int> gcd;

    int min_denom;

    int denom1_temp = denom1;
    int denom2_temp = denom2;

    while (1)
    {
        bool has_cd = false;

        denom1_temp < denom2_temp ? (min_denom = denom1_temp) : (min_denom = denom2_temp);
        if (min_denom != 1)
        {
            for (int i = 2; i <= min_denom; i++)
            {
                if ((denom1_temp % i == 0) && (denom2_temp % i == 0))
                {
                    has_cd = true;
                    gcd.push_back(i);

                    denom1_temp /= i;
                    denom2_temp /= i;

                    break;
                }
            }
        }
        else
        {
            gcd.push_back(1);
        }

        if (!has_cd)
        {
            gcd.push_back(denom1_temp);
            gcd.push_back(denom2_temp);
            break;
        }
    }
    
 
    
    int result = 1;
    for (const auto& i : gcd)
    { 
        result *= i;
    }


    //denom1
    while (denom1 != result)
    {
        if (denom1 == result)
            break;
        numer1 *= (result / denom1);
        denom1 *= (result / denom1);
    }

    //denom2
    while (denom2 != result)
    {
        if (denom2 == result)
            break;
        numer2 *= (result / denom2);
        denom2 *= (result / denom2);
    }

    numer1 += numer2;


    int min_result = 0;



    // irreducible fraction
    while (1)
    {
        bool has_cd = false;
        denom1 <= numer1 ? (min_result = denom1) : (min_result = numer1);

        if (min_result != 1)
        {
           
            for (int i = 2; i <= min_result; i++)
            {
                if ( (denom1 % i == 0) && (numer1 % i == 0))
                {
                    numer1 /= i;
                    denom1 /= i;
                    has_cd = true;
                    break;
                }
            }
        }

        if (!has_cd)
            break;
    }


    answer.push_back(numer1);
    answer.push_back(denom1);
    
    return answer;
}
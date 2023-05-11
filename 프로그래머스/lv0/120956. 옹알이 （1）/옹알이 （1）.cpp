#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> pn{ "aya","ye","woo","ma" };

    for (int i = 0; i < babbling.size(); i++)
    {
        for (int j = 0; j < pn.size(); j++)
        {
            if (babbling[i] == (pn[j]))
            {
                ++answer;
            }
            for (int k = 0; k < pn.size(); k++)
            {
                if (j != k)
                {
                    if (babbling[i] == (pn[j] + pn[k]))
                    {
                        ++answer;

                    }
                }
                for (int l = 0; l < pn.size(); l++)
                {
                    if ((j != k && j != l)
                        && (k != l))
                    {
                        if (babbling[i] == (pn[j] + pn[k] + pn[l]))
                        {
                            ++answer;


                        }
                    }
                    for (int p = 0; p < pn.size(); p++)
                    {
                        if((j != k && j != l && j!=p)
                            && (k !=l && k !=p )
                            && (l != p))
                        {
                            if (babbling[i] == (pn[j] + pn[k] + pn[l] + pn[p]))
                            {
                                ++answer;

                            }
                        }
                    }
                }
            }
        }
    }

return answer;
}
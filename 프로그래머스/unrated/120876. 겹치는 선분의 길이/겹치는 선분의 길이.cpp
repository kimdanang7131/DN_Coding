#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void AddOverlappedPair(const vector<vector<int>>& lines , vector<pair<int,int>>& sePair , const int& s, const int& e)
{
    
    if(lines[e][0] >= lines[s][0] && lines[e][0] < lines[s][1])
    {
        sePair.push_back(make_pair(lines[e][0],min(lines[s][1],lines[e][1])));
    }
    else if(lines[s][0] >= lines[e][0] && lines[s][0] < lines[e][1])
    {
        sePair.push_back(make_pair(lines[s][0],min(lines[s][1],lines[e][1])));
    }
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    
    return a.first < b.first;
}


    int solution(vector<vector<int>> lines) {
        int answer = 0;
        vector<pair<int, int>> sePair;

        AddOverlappedPair(lines, sePair, 0, 1);
        AddOverlappedPair(lines, sePair, 0, 2);
        AddOverlappedPair(lines, sePair, 1, 2);


        sort(sePair.begin(), sePair.end(), cmp);

        if (sePair.size())
        {
            int start = sePair[0].first;
            int end = sePair[0].second;

            if (sePair.size() == 1)
                return end - start;
            else
            {

                int count = 1;
                while (count < 3)
                {
                    for (int i = count; i < sePair.size(); i++)
                    {
                        if (end >= sePair[i].first && end <= sePair[i].second)
                        {
                            end = sePair[i].second;

                            if (i == sePair.size() - 1)
                            {
                                answer += (end - start);
                                return answer;
                            }
                        }

                        else
                        {
                            answer += (end - start);

                            if (sePair.size() - (i + 1) > 0)
                            {
                                break;
                            }
                            else
                            {
                                answer += (sePair[i].second - sePair[i].first);
                                return answer;
                            }
                        }
                    }
                    ++count;
                }
            }
        }
        else
            return 0;

        return answer;
    }
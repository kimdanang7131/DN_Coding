#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    list<int> burgerList;
    int breadCount = 0;
    for(const int& i : ingredient)
    {
        if(burgerList.empty())
        {
            if( i == 1 )
                breadCount++;
            
            burgerList.push_back(i);
            continue;
        }
        
        if( i == 1 ) // 빵 일때
        {
            if(burgerList.back() == 1 || breadCount <= 0) // 연속된 빵이거나 빵이 없었다면 그냥 넣고 cotinue;
            {
                breadCount++;
                burgerList.push_back(i);
                continue;
            }
            
            // 빵이 한개라도 있다면 체크
            if(breadCount > 0)
            {
                auto iter = burgerList.rbegin();
                int checkNum = 3;
                bool check = false;
                
                for( ; iter != burgerList.rend(); iter++)
                {
                    if(*iter == checkNum)
                    {
                        if(checkNum == 1) //  고기 야채 빵 까지 왔다면
                        {
                            check =true;
                            break;
                        }
                        checkNum--;
                        continue;
                    }
                    else // 실패했다면 break;
                    {
                        breadCount++;
                        burgerList.push_back(1);
                        break;
                    }
                }
                
                if(check)
                {
                    ++answer;
                    --breadCount;
                    for(int i=0; i<3; i++) // 고기 야채 빵 지우기
                    {
                        burgerList.pop_back();
                    }
                }
            }
        }
        else // 빵이 아닐때
        {
            burgerList.push_back(i);
        }
            
    }
    
    
    return answer;
}
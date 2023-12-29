#include <string>
#include <vector>

// n미터의 벽
// 1 ~ n 번까지 번호
// 롤러의 길이는 m미터

// 롤러로 벽에 페인트를 한 번 칠하는 규칙
// 롤러가 벽에서 벗어나면 X
// 구역의 일부분만 포함되도록 칠하면 X

// section은 칠해야 할 부분


using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<bool> wall(n + 1,true);
    
    for(int i=0; i < section.size(); i++)
    {
        int empty = section[i];
        wall[empty] = false;
    }
    
    int secCount = 0;
    int maxCount = section.size();

    for(int i = section[secCount]; i <= wall.size(); i = section[secCount])
    {
        if(wall[i] == true)
        {
            ++secCount;
            if(secCount > maxCount)
                break;
            
            continue;
        }
        
        if(i >= wall.size() - m)
        {   
            ++answer;    
            break;
        }
        
        for(int k = i; k < i + m; k++)
            wall[k] = true;
        
        ++answer;
        ++secCount;
        if(secCount > maxCount)
            break;
    }

    return answer;
}
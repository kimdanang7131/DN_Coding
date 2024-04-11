#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 영문 대소문자, 숫자, 공백(" "), 마침표("."), 빼기 부호("-")만으로 이루어져 있다
// 파일명은 영문자로 시작하며, 숫자를 하나 이상 포함하고 있다.

// HEAD 숫자가 아닌 문자 , NUMBER 한 글자에서 최대 다섯 글자 사이의 연속된 숫자 00000이나 0101 , 
// TAIL 여기에는 숫자가 다시 나타날 수도 있으며, 아무 글자도 없을 수 있다.

typedef struct _file
{
    string original = "";
    string HEAD = "";
    int NUMBER  = 0;
    string TAIL = "";
}File;

bool cmp(const File& a , const File& b)
{
    if(a.HEAD == b.HEAD)
        return a.NUMBER < b.NUMBER;
        
    return a.HEAD < b.HEAD;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> FileVec(files.size());
    
    for(int i=0; i < files.size(); i++)
    {
        FileVec[i].original = files[i];
        
        int tailIdx = -1;
        char c;
        string temp = "";
        
        for(int j = 0; j < files[i].size(); j++)
        {
            c = files[i][j];
            
            if(isdigit(c))
                break;
            
            tailIdx = j;
            temp += tolower(c);
        }
        
        FileVec[i].HEAD = temp;
        temp = "";
        
        for(int k = tailIdx + 1; k < files[i].size(); k++)
        {
            c = files[i][k];
            
            if(isdigit(c) == false)
                break;
            
            temp += c;
            tailIdx = k;
        }
        
        FileVec[i].NUMBER = stoi(temp);
        temp = "";
        
        temp = files[i].substr(tailIdx + 1);
        
        FileVec[i].TAIL = temp;
    }
    
    stable_sort(FileVec.begin() , FileVec.end() , cmp);
    
    for(int i=0; i<FileVec.size(); i++)
        answer.push_back(FileVec[i].original);
    
    return answer;
}
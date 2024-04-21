#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> alphaVec(26, 0); 

    int maxIdx = -1;
    int maxCnt = -1;
    for (int i = 0; i < str.size(); i++) {
        int idx = tolower(str[i]) - 'a';  
        alphaVec[idx] += 1;

        if (maxCnt < alphaVec[idx]) 
		{
            maxIdx = idx;
            maxCnt = alphaVec[idx];
        }
    }

    int chk = 0;
    for (int i = 0; i < alphaVec.size(); i++) 
	{
        if (maxCnt == alphaVec[i])
            chk++;

        if (chk >= 2) 
		{
            cout << '?' << endl;
            return 0;
        }
    }

    char c = (char)(maxIdx + 'A');  
    cout << c << endl;

    return 0;
}

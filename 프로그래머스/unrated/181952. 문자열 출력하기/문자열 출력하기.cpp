#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    if(str.length() >= 1 && str.length() <= 1000000)
        cout << str << endl;
    return 0;
}
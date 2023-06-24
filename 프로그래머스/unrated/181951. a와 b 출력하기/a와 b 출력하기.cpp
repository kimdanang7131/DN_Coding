#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    if((a >= -100000 && a <= 100000) && (b >= -100000 && b<= 100000))
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
     
    return 0;
}
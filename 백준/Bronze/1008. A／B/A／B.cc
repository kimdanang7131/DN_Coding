#include <iostream>
using namespace std;

int main()
{
    int A, B;
    A = B = 0;

    cin >> A >> B;
    printf("%.9lf\n", static_cast<double>(A) / B);

    return 0;
}
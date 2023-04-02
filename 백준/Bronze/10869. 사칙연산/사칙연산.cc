#include <iostream>
using namespace std;

int Add(int A, int B)
{
	return A + B;
}

int Sub(int A, int B)
{
	return A - B;
}

int Mul(int A, int B)
{
	return A * B;
}

int Div(int A, int B)
{
	return A / B;
}

int Remain(int A, int B)
{
	return A % B;
}


int Calculate(int A, int B, int (*CalFcn)(int, int))
{
	return CalFcn(A,B);
}


int main()
{
	int A, B;

	cin >> A >> B;

	cout << Calculate(A, B, Add) << endl;
	cout << Calculate(A, B, Sub) << endl;
	cout << Calculate(A, B, Mul) << endl;
	cout << Calculate(A, B, Div) << endl;
	cout << Calculate(A, B, Remain) << endl;
	return 0;
}

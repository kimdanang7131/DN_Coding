#include <iostream>
using namespace std;


int main()
{
	int A, B;

	cin >> A >> B;
	int sel;

	sel = A == B ? 0 : ((A < B) ? -1 : 1);

	switch (sel)
	{
	case -1:
		cout << "<" << endl;
		break;
	case 0:
		cout << "==" << endl;
		break;
	case 1:
		cout << ">" << endl;
		break;
	default:
		break;
	}
	
	return 0;
}
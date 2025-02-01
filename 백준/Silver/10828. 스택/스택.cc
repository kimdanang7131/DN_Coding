#include <iostream>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff
#define MAX 10000

int n;

class Stack
{
	int top = -1;
	int stk[MAX];
	
public:
	void push(const int& x);
	int pop();
	int size();
	int empty();
	int Top();
};

void Stack::push(const int& x)
{
	top++;
	stk[top] = x;
}

int Stack::pop()
{
	if(top == -1)
		return -1;
	
	int ret = stk[top];
	top--;
	
	return ret;
}

int Stack::size()
{
	return top + 1;
}

int Stack::empty()
{
	return (top == -1) ? 1 : 0;
}

int Stack::Top()
{
	if(top == -1)
		return -1;
	
	return stk[top];
}


int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	Stack* stk  = new Stack();
	cin >> n;
	
	while(n--)
	{
		string a;
		cin >> a;
		
		if(a == "push")
		{
			int b;
			cin >> b;
			
			stk->push(b);
		}
		else if(a == "top")
		{
			cout << stk->Top() << endl;
		}
		else if(a == "size")
		{
			cout << stk->size() << endl;
		}
		else if(a == "empty")
		{
			cout << stk->empty() << endl;
		}
		else if(a == "pop")
		{
			cout << stk->pop() << endl;
		}
	}	
	
	return 0;
} 
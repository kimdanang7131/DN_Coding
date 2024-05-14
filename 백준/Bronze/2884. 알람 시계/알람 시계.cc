#include <iostream>

using namespace std;

int h,m;

int convertToMin(const int& h, const int& m)
{
	int t = h * 60  + m;
	return t;
}

pair<int,int> convertToTime(const int& time)
{
	pair<int,int> p;
	p.first  = time / 60;
	p.second = time % 60;
	
	return p;	
}

int main()
{	
	cin >> h >> m;
	
	int time = 0;
	time = convertToMin(h,m);
	
	time -= 45;
		
	pair<int,int> timeP;
	
	if(time < 0)
	{
		timeP.first   = 23;
		timeP.second  = 60 + time;
	}
	else
	{
		timeP = convertToTime(time);
	}
	cout << timeP.first << " " << timeP.second << endl;

	return 0;
}
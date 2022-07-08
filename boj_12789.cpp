#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	queue<int> qLine;
	stack<int> sLine;
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		qLine.push(iNumber);
	}
	int iOrder = 1;
	while (!qLine.empty())
	{
		int iTop = qLine.front();
		if (iOrder == iTop)
		{
			++iOrder;
		}
		else
		{
			sLine.push(iTop);
		}
		qLine.pop();
		while (!sLine.empty() && iOrder == sLine.top())
		{
			++iOrder;
			sLine.pop();
		}
	}
	if (iOrder - 1 == iN)
	{
		cout << "Nice" << endl;
	}
	else
	{
		cout << "Sad" << endl;
	}
	return 0;
}

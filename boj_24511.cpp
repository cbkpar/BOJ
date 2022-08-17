#include <iostream>
#include <memory.h>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int iN;
	cin >> iN;
	bool* arrIsQueue = new bool[iN];
	memset(arrIsQueue, false, sizeof(bool) * iN);
	queue<int> queueNumber;
	stack<int> stackNumber;
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		if (0 == iNumber)
		{
			arrIsQueue[i] = true;
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		if (arrIsQueue[i])
		{
			stackNumber.emplace(iNumber);
		}
	}
	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iNumber;
		cin >> iNumber;
		queueNumber.emplace(iNumber);
		if (0 == stackNumber.size())
		{
			cout << queueNumber.front();
			queueNumber.pop();
		}
		else
		{
			cout << stackNumber.top();
			stackNumber.pop();
		}
		cout << (i + 1 == iM ? "\n" : " ");
	}
	delete[] arrIsQueue;
	return 0;
}

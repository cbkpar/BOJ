#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> qCard;
	vector<int> vecTemp;

	int iN;
	cin >> iN;
	vector<int> vecAns(iN, 0);

	for (int i = 0; i < iN; ++i)
	{
		qCard.push(i);
	}
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int iNum = qCard.front();
			qCard.pop();
			qCard.push(iNum);
		}
		vecTemp.push_back(qCard.front());
		qCard.pop();
	}

	for (int i = 0; i < iN; ++i)
	{
		vecAns[vecTemp[i]] = i + 1;
	}

	for (int i = 0; i < iN; ++i)
	{
		cout << vecAns[i] << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}

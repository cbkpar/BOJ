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

	int iN, iL;
	cin >> iN >> iL;

	vector<int> vecNum(iL, 0);
	for (int i = 0;i < iL;++i)
	{
		cin >> vecNum[i];
	}

	queue<int> qNum;
	for (int i = 1;i <= iN;++i)
	{
		qNum.push(i);
	}

	int iIndex = 0;
	for (int i = 0;i < iN - 1;++i)
	{
		int iCount = vecNum[(iIndex++) % iL] - 1;
		for (int j = 0;j < iCount;++j)
		{
			int iNum = qNum.front();
			qNum.pop();
			qNum.push(iNum);
		}
		qNum.pop();
	}

	cout << qNum.front() << "\n";
	return 0;
}

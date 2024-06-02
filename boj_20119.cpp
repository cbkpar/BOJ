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

	int iN, iM;
	cin >> iN >> iM;

	vector<bool> vecPossible(iN + 1, false);
	vector<vector<int>> vecNode(iN + 1, vector<int>());
	vector<int> vecPortion(iM, 0);
	vector<int> vecCount(iM, 0);

	for (int i = 0;i < iM;++i)
	{
		cin >> vecCount[i];
		for (int j = 0;j < vecCount[i];++j)
		{
			int iNum;
			cin >> iNum;
			vecNode[iNum].push_back(i);
		}
		cin >> vecPortion[i];
	}

	int iAns;
	cin >> iAns;
	queue<int> qNum;

	for (int i = 0;i < iAns;++i)
	{
		int iNum;
		cin >> iNum;
		qNum.push(iNum);

		vecPossible[iNum] = true;
	}

	while (!qNum.empty())
	{
		int iNum = qNum.front();
		qNum.pop();

		for (int iPart : vecNode[iNum])
		{
			if (--vecCount[iPart] == 0)
			{
				if (!vecPossible[vecPortion[iPart]])
				{
					vecPossible[vecPortion[iPart]] = true;
					qNum.push(vecPortion[iPart]);
					++iAns;
				}
			}
		}
	}

	cout << iAns << "\n";
	for (int i = 1;i <= iN;++i)
	{
		if (vecPossible[i])
		{
			cout << i << (--iAns == 0 ? "\n" : " ");
		}
	}
	return 0;
}

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

	int iN;
	cin >> iN;
	vector<int> vecCount(iN, 0);
	vector<int> vecTime(iN, 0);
	vector<vector<int>> vecStore(iN, vector<int>());
	vector<int> vecParent(iN, 0);

	for (int i = 0;i < iN;++i)
	{
		cin >> vecParent[i];
		if (vecParent[i] == -1) continue;
		++vecCount[vecParent[i]];
	}

	queue<int> qNum;
	for (int i = 0;i < iN;++i)
	{
		if (vecCount[i] == 0)
		{
			qNum.push(i);
		}
	}

	while (!qNum.empty())
	{
		int iNum = qNum.front();
		qNum.pop();

		int iParent = vecParent[iNum];
		if (iParent == -1) continue;

		vecStore[iParent].push_back(vecTime[iNum] + 1);
		if (--vecCount[iParent] == 0)
		{
			sort(vecStore[iParent].begin(), vecStore[iParent].end(), greater<>());
			int iSize = vecStore[iParent].size();
			int iMax = 0;
			for (int i = 0;i < iSize;++i)
			{
				iMax = max(iMax, vecStore[iParent][i] + i);
			}
			vecTime[iParent] = iMax;
			qNum.push(iParent);
		}
	}

	cout << vecTime[0] << "\n";
	return 0;
}

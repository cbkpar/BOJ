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

	int iN, iK;
	cin >> iN >> iK;

	queue<pair<int, int>> qNum;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iK; ++j)
		{
			pair<int, int> pNum;
			pNum.first = i + 1;
			cin >> pNum.second;
			qNum.push(pNum);
		}
	}

	for (int t = 0; t < iN * iK - 1; ++t)
	{
		pair<int, int> pNum = qNum.front();
		qNum.pop();

		int iSize = qNum.size();
		int iCount = (pNum.second - 1)%iSize;
		for (int i = 0; i < iCount; ++i)
		{
			pair<int, int> pTemp = qNum.front();
			qNum.pop();
			if (i != iCount)
			{
				qNum.push(pTemp);
			}
		}
	}
	
	cout << qNum.front().first << " " << qNum.front().second << "\n";
	return 0;
}

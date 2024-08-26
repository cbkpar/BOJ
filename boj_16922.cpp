#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arrNum[4] = { 1,5,10,50 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecVisited(2001, false);

	int iN;
	cin >> iN;

	queue<int> qNum;
	qNum.push(0);

	while (iN--)
	{
		for (int i = 0; i <= 2000;++i)
		{
			vecVisited[i] = false;
		}

		int iSize = qNum.size();
		while (iSize-- > 0)
		{
			int iNum = qNum.front();
			qNum.pop();

			for (int i = 0;i < 4;++i)
			{
				int iNext = iNum + arrNum[i];
				if (!vecVisited[iNext])
				{
					vecVisited[iNext] = true;
					qNum.push(iNext);
				}
			}
		}
	}

	int iAns = 0;
	for (int i = 0;i <= 2000;++i)
	{
		if (vecVisited[i])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}

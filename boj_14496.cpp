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

	int iStart, iEnd;
	cin >> iStart >> iEnd;

	int iN, iM;
	cin >> iN >> iM;

	vector<bool> vecVisited(iN + 1);
	vector<vector<int>> vecWays(iN + 1);
	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecWays[iS].push_back(iE);
		vecWays[iE].push_back(iS);
	}
	queue<int> qPos;
	qPos.push(iStart);
	vecVisited[iStart] = true;

	int iCount = 0;
	while (qPos.size() > 0)
	{
		int iSize = qPos.size();
		while (iSize--)
		{
			int iNowNum = qPos.front();
			qPos.pop();

			if (iNowNum == iEnd)
			{
				cout << iCount << "\n";
				return 0;
			}

			for (int iNext : vecWays[iNowNum])
			{
				if (!vecVisited[iNext])
				{
					vecVisited[iNext] = true;
					qPos.push(iNext);
				}
			}
		}
		++iCount;
	}

	cout << "-1\n";
	return 0;
}

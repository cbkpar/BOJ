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
	vector<int> vecPeople(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecPeople[i];
	}

	vector<vector<int>> vecNode(iN + 1, vector<int>());
	for (int i = 1;i <= iN;++i)
	{
		int iCount;
		cin >> iCount;

		for (int j = 0;j < iCount;++j)
		{
			int iEnd;
			cin >> iEnd;
			vecNode[i].push_back(iEnd);
		}
	}

	int iAns = 1000000000;
	for (int t = 0;t < 1 << iN;++t)
	{
		int iTeam = t;
		vector<bool> vecRed(iN + 1, false);
		for (int i = 1;i <= iN;++i)
		{
			if (iTeam % 2 == 1)
			{
				vecRed[i] = true;
			}
			iTeam >>= 1;
		}

		int iRed = 0;
		int iBlue = 0;
		int iRedCount = 0;
		int iBlueCount = 0;
		vector<bool> vecVisited(iN + 1, false);

		for (int i = 1;i <= iN;++i)
		{
			if (vecVisited[i]) continue;
			vecVisited[i] = true;
			queue<int> qPos;
			qPos.push(i);
			if (vecRed[i])
			{
				++iRedCount;
			}
			else
			{
				++iBlueCount;
			}

			while (!qPos.empty())
			{
				int iPos = qPos.front();
				qPos.pop();

				if (vecRed[iPos])
				{
					iRed += vecPeople[iPos];
				}
				else
				{
					iBlue += vecPeople[iPos];
				}

				for (int iNext : vecNode[iPos])
				{
					if (!vecVisited[iNext] && vecRed[iPos] == vecRed[iNext])
					{
						vecVisited[iNext] = true;
						qPos.push(iNext);
					}
				}
			}
		}

		if (iRedCount == 1 && iBlueCount == 1)
		{
			iAns = min(iAns, abs(iRed - iBlue));
		}
	}

	if (iAns == 1000000000)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << iAns << "\n";
	}
	return 0;
}

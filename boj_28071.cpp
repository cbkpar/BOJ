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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<bool> vecVisited(90001, false);
	queue<int> qPos;

	vecVisited[0] = true;
	qPos.push(0);

	while (iM--)
	{
		int iSize = qPos.size();
		while (iSize--)
		{
			int iNowPos = qPos.front();
			qPos.pop();

			for (int i = 0; i < iN; ++i)
			{
				int iNextPos = iNowPos + vecNum[i];
				if (!vecVisited[iNextPos])
				{
					vecVisited[iNextPos] = true;
					qPos.push(iNextPos);
				}
			}
		}
	}
	int iAns = 0;
	for (int i = 90000; i >= 0; --i)
	{
		if (vecVisited[i] && i % iK == 0)
		{
			iAns = i;
			break;
		}
	}
	cout << iAns << "\n";
	return 0;
}

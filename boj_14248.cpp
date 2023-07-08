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

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	int iNow;
	cin >> iNow;

	vector<bool> vecVisited(iN + 1, false);
	queue<int> qPos;
	vecVisited[iNow] = true;
	qPos.push(iNow);

	while (!qPos.empty())
	{
		int iNowPos = qPos.front();
		qPos.pop();
		for (int i = -1; i <= 1; i += 2)
		{
			int iNextPos = iNowPos + vecNum[iNowPos] * i;
			if (iNextPos <= 0 || iNextPos > iN) continue;
			if (vecVisited[iNextPos]) continue;
			vecVisited[iNextPos] = true;
			qPos.push(iNextPos);
		}
	}

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		if (vecVisited[i])
		{
			++iAns;
		}
	}
	cout << iAns << "\n";
	return 0;
}

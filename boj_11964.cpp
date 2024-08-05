#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool Visited[5000001][2] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT, iA, iB;
	cin >> iT >> iA >> iB;

	int iAns = 0;
	queue<pair<int, int>> qNow;
	qNow.push({ 0, 0 });
	Visited[0][0] = true;

	while (!qNow.empty())
	{
		pair<int, int> pNow = qNow.front();
		qNow.pop();

		iAns = max(iAns, pNow.first);

		int iNextA = pNow.first + iA;
		if (iNextA <= iT && !Visited[iNextA][pNow.second])
		{
			qNow.push({ iNextA, pNow.second });
			Visited[iNextA][pNow.second] = true;
		}

		int iNextB = pNow.first + iB;
		if (iNextB <= iT && !Visited[iNextB][pNow.second])
		{
			qNow.push({ iNextB, pNow.second });
			Visited[iNextB][pNow.second] = true;
		}

		if (pNow.second == 0 && !Visited[pNow.first / 2][1])
		{
			qNow.push({ pNow.first / 2, 1 });
			Visited[pNow.first / 2][1] = true;
		}
	}

	cout << iAns << "\n";
	return 0;
}

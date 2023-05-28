#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dR[8] = { -1,-2,-2,-1,1,2,2,1 };
int dC[8] = { -2,-1,1,2,-2,1,-1,2 };

int CalcCount(const pair<int, int>& pFrom, const pair<int, int>& pDest)
{
	int iCount = 0;
	queue<pair<int, int>> qPos;
	vector<vector<bool>> matVisited(8, vector<bool>(8, false));

	qPos.push(pFrom);
	matVisited[pFrom.first][pFrom.second] = true;

	while (!qPos.empty())
	{
		int iSize = qPos.size();
		while (iSize--)
		{
			pair<int, int> NowPos = qPos.front();
			qPos.pop();
			if (NowPos.first == pDest.first && NowPos.second == pDest.second)
			{
				return iCount;
			}
			for (int i = 0; i < 8; ++i)
			{
				pair<int, int> pNext;
				pNext.first = NowPos.first + dR[i];
				pNext.second = NowPos.second + dC[i];
				if (pNext.first < 0 || pNext.first > 7 || pNext.second < 0 || pNext.second > 7) continue;
				if (matVisited[pNext.first][pNext.second]) continue;
				qPos.push(pNext);
				matVisited[pNext.first][pNext.second] = true;
			}
		}
		++iCount;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strFrom, strDest;
	while (cin >> strFrom >> strDest)
	{
		pair<int, int> pFrom, pDest;
		pFrom.first = strFrom[0] - 'a';
		pFrom.second = strFrom[1] - '1';
		pDest.first = strDest[0] - 'a';
		pDest.second = strDest[1] - '1';
		int iAns = CalcCount(pFrom, pDest);

		cout << "To get from " << strFrom << " to " << strDest << " takes " << iAns << " knight moves.\n";
	}
	return 0;
}

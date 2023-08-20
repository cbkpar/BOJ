#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		vector<int> vecRet(100, 0);
		int iNow = 1;
		for (int i = 0; i < 100; ++i)
		{
			vecRet[i] = iNow;
			iNow *= 10;
			iNow %= iN;
			if (iNow == 0) iNow = iN;
		}

		vector<bool> vecVisited(iN + 1, false);
		vector<bool> vecTemp(iN + 1, false);
		vecVisited[0] = true;
		vecTemp[0] = true;
		vector<string> vecAns(iN + 1, "");

		vector<int> vecPos;
		vecPos.push_back(0);

		queue<int> qNext;

		for (int i = 0; i < 100; ++i)
		{
			for (int j : vecPos)
			{
				int iNext = (j + vecRet[i] + iN - 1) % iN + 1;
				if (!vecTemp[iNext])
				{
					vecTemp[iNext] = true;
					qNext.push(iNext);

					int iLen = vecAns[j].length();
					vecAns[iNext].resize(i + 1);
					vecAns[iNext][0] = '1';
					for (int k = 1; k < i + 1 - iLen; ++k)
					{
						vecAns[iNext][k] = '0';
					}
					int iIndex = 0;
					for (int k = i + 1 - iLen; k < i + 1; ++k)
					{
						vecAns[iNext][k] = vecAns[j][iIndex++];
					}
				}
			}

			while (!qNext.empty())
			{
				int iNext = qNext.front();
				qNext.pop();
				vecPos.push_back(iNext);
				vecVisited[iNext] = true;
			}

			if (vecVisited[iN]) break;
		}
		if (vecVisited[iN])
		{
			cout << vecAns[iN] << "\n";
		}
		else
		{
			cout << "BRAK" << "\n";
		}
	}
	return 0;
}

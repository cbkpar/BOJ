#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iQ;
	cin >> iN >> iQ;

	vector<pair<int, int>> vecNum;
	vecNum.push_back({ 0,0 });

	vector<int> vecUsed(iN + 1, 0);

	while (iQ--)
	{
		string strCommand;
		cin >> strCommand;

		if (strCommand == "new")
		{
			int iX, iY;
			cin >> iX >> iY;

			int iCount = 0;
			bool bPossible = false;

			for (int i = 1; i <= iN; ++i)
			{
				if (vecUsed[i] == 0)
				{
					if (++iCount == iY)
					{
						bPossible = true;
						for (int j = i; j > i - iCount; --j)
						{
							vecUsed[j] = iX;
						}
						vecNum.push_back({ i - iCount + 1, iY });
						break;
					}
				}
				else
				{
					iCount = 0;
				}
			}

			if (bPossible)
			{
				int iIndex = vecNum.size() - 1;
				cout << vecNum[iIndex].first << " " << (vecNum[iIndex].first + iY - 1) << "\n";
			}
			else
			{
				cout << "REJECTED" << "\n";
			}
		}

		if (strCommand == "in")
		{
			int iA, iB;
			cin >> iA >> iB;
			vecUsed[vecNum[iA].first] += iB;
		}

		if (strCommand == "out")
		{
			int iA, iB;
			cin >> iA >> iB;
			vecUsed[vecNum[iA].first] -= iB;
			if (vecUsed[vecNum[iA].first] == 0)
			{
				for (int i = 0; i < vecNum[iA].second; ++i)
				{
					vecUsed[vecNum[iA].first + i] = 0;
				}
				cout << "CLEAN " << vecNum[iA].first << " " << (vecNum[iA].first + vecNum[iA].second - 1) << "\n";
			}
		}
	}

	return 0;
}

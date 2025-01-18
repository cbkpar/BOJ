#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dR[4] = { -1, 0, 1, 0 };
int dC[4] = { 0, -1, 0, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		vector<string> vecWord(3, "");
		for (int i = 0;i < 3;++i)
		{
			cin >> vecWord[i];
		}

		int iN;
		cin >> iN;
		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}

		vector<int> vecCount;

		vector<vector<bool>> vecVisited(3, vector<bool>(3, false));

		for (int i = 0;i < 3;++i)
		{
			for (int j = 0;j < 3;++j)
			{
				if (vecWord[i][j] == 'O' && vecVisited[i][j] == false)
				{
					queue<pair<int, int>> qPos;
					qPos.push({ i,j });
					vecVisited[i][j] = true;

					int iCount = 1;

					while (!qPos.empty())
					{
						pair<int, int> pPos = qPos.front();
						qPos.pop();
						for (int k = 0;k < 4;++k)
						{
							int iNextR = pPos.first + dR[k];
							int iNextC = pPos.second + dC[k];
							if (iNextR < 0 || iNextR >= 3 || iNextC < 0 || iNextC >= 3) continue;
							if (vecVisited[iNextR][iNextC] == false && vecWord[iNextR][iNextC] == 'O')
							{
								++iCount;
								qPos.push({ iNextR, iNextC });
							}
							vecVisited[iNextR][iNextC] = true;
						}
					}
					vecCount.push_back(iCount);
				}
			}
		}

		sort(vecCount.begin(), vecCount.end());
		bool bPossible = true;
		if (vecCount.size() == iN)
		{
			for (int i = 0;i < iN;++i)
			{
				if (vecCount[i] != vecNum[i])
				{
					bPossible = false;
					break;
				}
			}
		}
		else
		{
			bPossible = false;
		}

		cout << (bPossible ? "1" : "0") << "\n";
	}
	return 0;
}

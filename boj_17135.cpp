#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class eState
{
	NONE = 0,
	ALIVE = 1,
	DEAD = 2,
};

int Solve(const vector<vector<int>>& matOrigin, const vector<int>& vecPos, const int& iDist)
{
	int iN = matOrigin.size();
	int iM = matOrigin[0].size();

	vector<vector<int>> matWorld(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			matWorld[i][j] = matOrigin[i][j];
		}
	}

	int iCount = 0;
	while (true)
	{
		for (int i = 0; i < 3; ++i)
		{
			int iNow = vecPos[i];
			bool bAttack = false;
			for (int k = 1; k <= iDist; ++k)
			{
				if (bAttack) break;
				for (int j = 0; j <= 2 * k; ++j)
				{
					int iNextC = iNow - k + j;
					if (iNextC < 0 || iNextC > iM - 1) continue;
					int iNextR = (j < k ? iN - j : iN - k + j - k);
					if (iNextR < 0 || iNextR > iN - 1) continue;

					if (matWorld[iNextR][iNextC] == static_cast<int>(eState::ALIVE))
					{
						++iCount;
						matWorld[iNextR][iNextC] = static_cast<int>(eState::DEAD);
						bAttack = true;
						break;
					}
					else if (matWorld[iNextR][iNextC] == static_cast<int>(eState::DEAD))
					{
						bAttack = true;
						break;
					}
				}
			}
		}

		bool bFound = false;
		for (int i = 0; i < iM; ++i)
		{
			for (int j = iN - 2; j >= 0; --j)
			{
				if (matWorld[j][i] == static_cast<int>(eState::ALIVE))
				{
					bFound = true;
					matWorld[j + 1][i] = static_cast<int>(eState::ALIVE);
				}
				else
				{
					matWorld[j + 1][i] = static_cast<int>(eState::NONE);
				}
			}
			matWorld[0][i] = static_cast<int>(eState::NONE);
		}
		if (!bFound) break;
	}
	return iCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iD;
	cin >> iN >> iM >> iD;

	vector<vector<int>> matOrigin(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			cin >> matOrigin[i][j];
		}
	}

	int iAns = 0;
	vector<int> vecPos(3, 0);
	for (int i = 0; i < iM; ++i)
	{
		vecPos[0] = i;
		for (int j = i + 1; j < iM; ++j)
		{
			vecPos[1] = j;
			for (int k = j + 1; k < iM; ++k)
			{
				vecPos[2] = k;
				iAns = max(iAns, Solve(matOrigin, vecPos, iD));
			}
		}
	}
	cout << iAns << "\n";
	return 0;
}

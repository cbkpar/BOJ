#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int dR[8] = { -1,-2,-2,-1,1,2,2,1 };
int dC[8] = { -2,-1,1,2,2,1,-1,-2 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iR, iC;
	cin >> iN >> iR >> iC;

	if (iN >= 4)
	{
		if ((iR + iC) % 2 == 0 && iN % 2 == 1)
		{
			long long lTemp = iN;
			cout << (lTemp * lTemp / 2 + 1) << "\n";
		}
		else
		{
			long long lTemp = iN;
			cout << (lTemp * lTemp / 2) << "\n";
		}

		return 0;
	}

	--iR;
	--iC;

	queue<pair<int, int>> qPos;
	qPos.push({ iR,iC });
	set<pair<int, int>> setPos;
	setPos.insert({ iR,iC });

	while (!qPos.empty())
	{
		set<pair<int, int>> setTempPos;
		for (int t = 0; t < 2; ++t)
		{
			int iSize = qPos.size();
			while (iSize-- > 0)
			{
				pair<int, int> pPos = qPos.front();
				qPos.pop();

				for (int i = 0; i < 8; ++i)
				{
					int iNextR = pPos.first + dR[i];
					int iNextC = pPos.second + dC[i];

					if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iN - 1) continue;
					if (t == 0)
					{
						if (setTempPos.find({ iNextR,iNextC }) == setTempPos.end())
						{
							qPos.push({ iNextR, iNextC });
							setTempPos.insert({ iNextR,iNextC });
						}
					}
					else
					{
						if (setPos.find({ iNextR,iNextC }) == setPos.end())
						{
							qPos.push({ iNextR, iNextC });
							setPos.insert({ iNextR,iNextC });
						}
					}
				}
			}
		}
	}

	cout << setPos.size() << "\n";
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int mapCount[1002][1002] = { 0, };
bool bVisited[1002][1002] = { false, };

int dR[4] = { -1,0,1,0 };
int dC[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iCount = 0;

	while (iN--)
	{
		int iR, iC;
		cin >> iR >> iC;
		++iR;
		++iC;
		for (int i = 0; i < 4; ++i)
		{
			int iNextR = iR + dR[i];
			int iNextC = iC + dC[i];
			if (bVisited[iNextR][iNextC])
			{
				++mapCount[iNextR][iNextC];
				++mapCount[iR][iC];

				if (mapCount[iNextR][iNextC] == 3)
				{
					++iCount;
				}
				else if (mapCount[iNextR][iNextC] == 4)
				{
					--iCount;
				}

				if (mapCount[iR][iC] == 3)
				{
					++iCount;
				}
				else if (mapCount[iR][iC] == 4)
				{
					--iCount;
				}

			}
		}

		bVisited[iR][iC] = true;
		cout << iCount << "\n";
	}

	return 0;
}

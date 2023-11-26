#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dR[4] = { 0,1,0,-1 };
int dC[4] = { 1,0,-1,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<bool>> matMap(iN, vector<bool>(iM, false));

	int iR = 0;
	int iC = 0;
	int iDir = 0;

	int iCount = 0;
	
	while (true)
	{
		matMap[iR][iC] = true;
		int iNextR = iR + dR[iDir];
		int iNextC = iC + dC[iDir];

		if (iNextR >= 0 && iNextR < iN && iNextC >= 0 && iNextC < iM && !matMap[iNextR][iNextC])
		{
			iR = iNextR;
			iC = iNextC;
		}
		else
		{
			iDir = (iDir + 1) % 4;
			iNextR = iR + dR[iDir];
			iNextC = iC + dC[iDir];
			if (matMap[iNextR][iNextC])
			{
				break;
			}
			++iCount;
			iR = iNextR;
			iC = iNextC;
		}
	}

	cout << iCount << "\n";
	return 0;
}

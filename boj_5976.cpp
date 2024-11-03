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

	int iN;
	cin >> iN;

	vector<vector<int>> matNum(iN, vector<int>(iN, 0));

	int iNowR = 0;
	int iNowC = 0;
	int iIndex = 1;
	int iDir = 0;
	matNum[0][0] = 1;

	while (true)
	{
		bool bFound = false;

		for (int i = 0; i < 4; ++i)
		{
			int iNextR = iNowR + dR[(iDir+i)%4];
			int iNextC = iNowC + dC[(iDir+i)%4];
			if (iNextR < 0 || iNextR > iN - 1 || iNextC < 0 || iNextC > iN - 1) continue;
			if (matNum[iNextR][iNextC] != 0) continue;
			
			matNum[iNextR][iNextC] = ++iIndex;
			iNowR = iNextR;
			iNowC = iNextC;
			iDir = (iDir + i) % 4;
			bFound = true;
			break;
		}

		if (!bFound)
		{
			break;
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cout << matNum[i][j] << (j == iN - 1 ? "\n" : " ");
		}
	}
	return 0;
}

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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		vector<string> vecRobot(iN, "");
		for (int i = 0; i < iN; ++i) cin >> vecRobot[i];

		vector<bool> vecAlive(iN, true);
		int iLen = vecRobot[0].length();
		
		int iAns = 0;

		for (int i = 0; i < iLen; ++i)
		{
			int iR = 0;
			int iS = 0;
			int iP = 0;

			for (int j = 0; j < iN; ++j)
			{
				if (!vecAlive[j]) continue;
				if (vecRobot[j][i] == 'R') ++iR;
				if (vecRobot[j][i] == 'S') ++iS;
				if (vecRobot[j][i] == 'P') ++iP;
			}
			if (iR > 0 && iP == 0)
			{
				for (int j = 0; j < iN; ++j)
				{
					if (vecRobot[j][i] == 'S') vecAlive[j] = false;
				}
			}
			if (iS > 0 && iR == 0)
			{
				for (int j = 0; j < iN; ++j)
				{
					if (vecRobot[j][i] == 'P') vecAlive[j] = false;
				}
			}
			if (iP > 0 && iS == 0)
			{
				for (int j = 0; j < iN; ++j)
				{
					if (vecRobot[j][i] == 'R') vecAlive[j] = false;
				}
			}

			int iCount = 0;
			int iNum = 0;
			for (int j = 0; j < iN; ++j)
			{
				if (vecAlive[j])
				{
					++iCount;
					iNum = j + 1;
				}
			}
			if (iCount == 1)
			{
				iAns = iNum;
				break;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
	vector<vector<int>> matUsed(iN, vector<int>(iM, 0));
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			cin >> matUsed[i][j];
		}
	}
	vector<vector<int>> matDist(iN, vector<int>(iM, 0));

	int iDist = 999999;
	int iAnsR = -1;
	int iAnsC = -1;
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iM;++j)
		{
			if (matUsed[i][j] == 1) continue;
			matDist[i][j] = (i + 1) + abs((iM + 1) / 2 - (j + 1));

			if (matDist[i][j] < iDist)
			{
				iDist = matDist[i][j];
				iAnsR = i + 1;
				iAnsC = j + 1;
			}
		}
	}
	if (iDist == 999999)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << iAnsR << " " << iAnsC << "\n";
	}
	return 0;
}

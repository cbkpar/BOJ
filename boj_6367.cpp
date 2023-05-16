#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vecColor(16, vector<int>(3, 0));
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> vecColor[i][j];
		}
	}
	while (true)
	{
		vector<int> vecTarget(3, 0);
		for (int i = 0; i < 3; ++i)
		{
			cin >> vecTarget[i];
		}
		if (vecTarget[0] == -1 && vecTarget[1] == -1 && vecTarget[2] == -1) break;
		int iDist = 1000000000;
		int iAns = -1;
		for (int i = 0; i < 16; ++i)
		{
			int iTempDist = 0;
			for (int j = 0; j < 3; ++j)
			{
				iTempDist += (vecColor[i][j] - vecTarget[j]) * (vecColor[i][j] - vecTarget[j]);
			}
			if (iTempDist < iDist)
			{
				iDist = iTempDist;
				iAns = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", vecTarget[0], vecTarget[1], vecTarget[2]
			, vecColor[iAns][0], vecColor[iAns][1], vecColor[iAns][2]);
	}
	return 0;
}

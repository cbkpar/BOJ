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

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	vector<vector<int>> vecCount(iN + 1, vector<int>(iM + 1, 0));
	for (int t = 0;t < iK;++t)
	{
		int iX1, iY1, iX2, iY2;
		cin >> iX1 >> iY1 >> iX2 >> iY2;
		for (int i = iX1;i <= iX2;++i)
		{
			for (int j = iY1;j <= iY2;++j)
			{
				++vecCount[i][j];
			}
		}
	}

	int iAns = 0;
	for (int i = 1;i <= iN;++i)
	{
		for (int j = 1;j <= iM;++j)
		{
			if (vecCount[i][j] > 0)
			{
				++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> vecNum(iN + 1, vector<int>(iM + 1, 0));
	int iMax = 0;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			int iNum;
			cin >> iNum;
			if (iNum == 0)
			{
				vecNum[i][j] = min(vecNum[i - 1][j - 1], min(vecNum[i][j - 1], vecNum[i - 1][j])) + 1;
				iMax = max(iMax, vecNum[i][j]);
			}
		}
	}
	cout << iMax << "\n";

	return 0;
}

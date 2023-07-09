#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecLen(iN, { 0,0 });
	for (int i = 0; i < iN; ++i)
	{
		int iX1, iY1, iX2, iY2;
		cin >> iX1 >> iY1 >> iX2 >> iY2;
		vecLen[i].first = iX2 - iX1;
		vecLen[i].second = iY2 - iY1;
		if (vecLen[i].first < vecLen[i].second)
		{
			swap(vecLen[i].first, vecLen[i].second);
		}
	}

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = i + 1; j < iN; ++j)
		{
			if (vecLen[i].first > vecLen[j].first)
			{
				if (vecLen[i].second < vecLen[j].second)
				{
					++iSum;
				}
			}
			if (vecLen[i].first < vecLen[j].first)
			{
				if (vecLen[i].second > vecLen[j].second)
				{
					++iSum;
				}
			}
		}
	}
	cout << iSum << "\n";
	return 0;
}

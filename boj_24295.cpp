#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void GetInput(int& width, int& height)
{
	int iWidthCm, iWidthMm, iHeightCm, iHeightMm;
	cin >> iWidthCm >> iWidthMm >> iHeightCm >> iHeightMm;

	width = iWidthCm * 10 + iWidthMm;
	height = iHeightCm * 10 + iHeightMm;

	if (width > height) swap(width, height);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vecLen(3, { 0,0 });
	for (int i = 0; i < 3; ++i)
	{
		GetInput(vecLen[i].first, vecLen[i].second);
	}
	int iAns = 0;
	int iMax = 10000000000;

	for (int i = 1; i < 3; ++i)
	{
		if (vecLen[0].first + 10 <= vecLen[i].first
			&& vecLen[0].second <= vecLen[i].second)
		{
			if (vecLen[i].first < iMax)
			{
				iMax = vecLen[i].first;
				iAns = i;
			}
		}
	}

	cout << iAns << "\n";
	if (iAns != 0)
	{
		cout << vecLen[iAns].first / 10 << "." << vecLen[iAns].first % 10 << " ";
		cout << vecLen[iAns].second / 10 << "." << vecLen[iAns].second % 10 << "\n";
	}

	return 0;
}

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

	long long lMaxX = 0;
	long long lMaxY = 0;

	for (int i = 0;i < iN;++i)
	{
		long long lTempX, lTempY;
		cin >> lTempX >> lTempY;

		if (lTempX > lTempY)
		{
			swap(lTempX, lTempY);
		}

		lMaxX = max(lTempX, lMaxX);
		lMaxY = max(lTempY, lMaxY);
	}

	cout << lMaxX * lMaxY << "\n";
	return 0;
}

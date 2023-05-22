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
	vector<int> vecLevel(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecLevel[i];
	sort(vecLevel.begin(), vecLevel.end());

	int iAns = -1;
	int iMax = 0;
	for (int i = 1; i < iN; ++i)
	{
		int iDiff = (vecLevel[i] - vecLevel[i - 1]) / 2;
		if (iDiff > iMax)
		{
			iMax = iDiff;
			iAns = vecLevel[i - 1] + iDiff;
		}
	}
	cout << iAns << "\n";
	return 0;
}

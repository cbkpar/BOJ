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

	vector<int> vecDist(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecDist[i];
	}

	sort(vecDist.begin(), vecDist.end());

	int iAns = 0;
	int iDist = 1000000000;

	for (int i = 1; i < iN; ++i)
	{
		int iDiff = vecDist[i] - vecDist[i - 1];
		if (iDiff < iDist)
		{
			iAns = 1;
			iDist = iDiff;
		}
		else if (iDiff == iDist)
		{
			++iAns;
		}
	}

	cout << iDist << " " << iAns << "\n";
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iR, iC;
	cin >> iR >> iC;

	int iN;
	cin >> iN;

	vector<long long> vecMaxX(iN + 1, -1);
	vector<long long> vecMinX(iN + 1, 1000000);
	vector<long long> vecMaxY(iN + 1, -1);
	vector<long long> vecMinY(iN + 1, 1000000);

	for (int i = 0;i < iN;++i)
	{
		int iA;
		long long iV, iH;
		cin >> iA >> iV >> iH;

		vecMaxX[iA] = max(vecMaxX[iA], iH);
		vecMinX[iA] = min(vecMinX[iA], iH);
		vecMaxY[iA] = max(vecMaxY[iA], iV);
		vecMinY[iA] = min(vecMinY[iA], iV);
	}

	int iAns = -1;
	long long lMaxSize = -1;

	for (int i = 1;i <= iN;++i)
	{
		if (vecMaxX[i] != -1)
		{
			long long lArea = (vecMaxX[i] - vecMinX[i] + 1) * (vecMaxY[i] - vecMinY[i] + 1);
			if (lArea > lMaxSize)
			{
				lMaxSize = lArea;
				iAns = i;
			}
		}
	}

	cout << iAns << " " << lMaxSize << "\n";
	return 0;
}

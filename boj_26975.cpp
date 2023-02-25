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

	vector<long long> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	sort(vecNum.begin(), vecNum.end());

	long long lMax = 0;
	long long lTuition = 0;
	for (int i = 0; i < iN; ++i)
	{
		long long lTemp = vecNum[i] * (iN - i);
		if (lTemp > lMax)
		{
			lTuition = vecNum[i];
			lMax = lTemp;
		}
	}
	cout << lMax << " " << lTuition << "\n";

	return 0;
}

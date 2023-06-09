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

	long long lAns = 0;
	for (int i = 1; i < iN - 1; ++i)
	{
		long long lMedian = vecNum[i] * 3;
		long long lMeanLeft = vecNum[0] + vecNum[i] + vecNum[i + 1];
		long long lMeanRight = vecNum[i - 1] + vecNum[i] + vecNum[iN - 1];
		lAns = max(lAns, max(abs(lMeanLeft - lMedian), abs(lMeanRight - lMedian)));
	}
	cout << lAns << "\n";
	return 0;
}

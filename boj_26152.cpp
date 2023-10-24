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

	vector<int> vecHigh(iN, 0);
	vector<int> vecLow(iN, 0);
	vector<int> vecDiff(iN, 0);

	for (int i = 0; i < iN; ++i) cin >> vecHigh[i];
	for (int i = 0; i < iN; ++i) cin >> vecLow[i];
	for (int i = 0; i < iN; ++i) vecDiff[i] = vecLow[i] - vecHigh[i];
	for (int i = 1; i < iN; ++i) if (vecDiff[i] < vecDiff[i - 1]) vecDiff[i] = vecDiff[i - 1];

	int iM;
	cin >> iM;

	for (int i = 0; i < iM; ++i)
	{
		int iHeight;
		cin >> iHeight;
		cout << (upper_bound(vecDiff.begin(), vecDiff.end(), -iHeight) - vecDiff.begin()) << "\n";
	}
	return 0;
}

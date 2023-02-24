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

	vector<int> vecMax(3, 0);
	vector<int> vecMin(3, 1000);

	while (iN--)
	{
		vector<int> vecNum(3);
		for (int i = 0; i < 3; ++i) cin >> vecNum[i];
		for (int i = 0; i < 3; ++i) vecMax[i] = max(vecMax[i], vecNum[i]);
		for (int i = 0; i < 3; ++i) cin >> vecNum[i];
		for (int i = 0; i < 3; ++i) vecMin[i] = min(vecMin[i], vecNum[i]);
	}
	long long lVolume = 1;
	for (int i = 0; i < 3; ++i)
	{
		lVolume *= (vecMin[i] > vecMax[i] ? (long long)(vecMin[i] - vecMax[i]) : 0);
	}
	cout << lVolume << "\n";
	return 0;
}

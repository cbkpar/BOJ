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
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecLevel[i];
	}
	sort(vecLevel.begin(), vecLevel.end(), greater<>());

	int iSumLevel = 0;
	int iSumPower = 0;
	
	int iCount = min(42, iN);
	for (int i = 0; i < iCount; ++i)
	{
		iSumLevel += vecLevel[i];
		if (vecLevel[i] >= 60) ++iSumPower;
		if (vecLevel[i] >= 100) ++iSumPower;
		if (vecLevel[i] >= 140) ++iSumPower;
		if (vecLevel[i] >= 200) ++iSumPower;
		if (vecLevel[i] >= 250) ++iSumPower;
	}
	
	cout << iSumLevel << " " << iSumPower << "\n";
	return 0;
}

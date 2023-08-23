#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iAns = 0;

	int iN;
	cin >> iN;

	vector<int> vecRun(2, 0);
	vector<int> vecTrick(5, 0);
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < 2; ++j) cin >> vecRun[j];
		for (int j = 0; j < 5; ++j) cin >> vecTrick[j];
		sort(vecRun.begin(), vecRun.end());
		sort(vecTrick.begin(), vecTrick.end());

		int iSum = vecRun[1] + vecTrick[3] + vecTrick[4];
		iAns = max(iAns, iSum);
	}
	cout << iAns << "\n";
	return 0;
}

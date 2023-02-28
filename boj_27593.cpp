#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(iN);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];
		int iCount = vecNum[0] / 120;
		for (int i = 1; i < iN; ++i) iCount += (vecNum[i] - vecNum[i - 1]) / 120;
		iCount += (1440 - vecNum[iN - 1]) / 120;

		cout << (iCount >= 2 ? "YES\n" : "NO\n");
	}

	return 0;
}

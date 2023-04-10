#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT = 1;
	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		vector<int> vecNum(iN);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];
		int iSum = vecNum[iN - 1 - iN / 2] + vecNum[iN / 2];
		cout << "Case " << iT << ": " << (iSum / 2) << "." << (iSum % 2 == 0 ? "0" : "5") << "\n";
		++iT;
	}
	return 0;
}

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
	for (int t = 1; t <= iT; ++t)
	{
		int iN, iP, iQ;
		cin >> iN >> iP >> iQ;

		vector<int> arrWeight(iN);
		for (int i = 0; i < iN; ++i) cin >> arrWeight[i];
		sort(arrWeight.begin(), arrWeight.end());
		int iCount = 0;
		for (int i = 0; i < iN && i < iP; ++i)
		{
			if (iQ < arrWeight[i]) break;
			iQ -= arrWeight[i];
			++iCount;
		}
		cout << "Case " << t << ": " << iCount << "\n";
	}
	return 0;
}

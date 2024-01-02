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

		int iH = 0;

		vector<int> vecHeight(iN, 0);
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecHeight[i];
			iH += vecHeight[i];
		}
		iH /= iN;

		int iAns = 0;
		for (int i = 0; i < iN; ++i)
		{
			if (vecHeight[i] > iH)
			{
				iAns += vecHeight[i] - iH;
			}
		}
		if (iT > 1) cout << "\n";
		cout << "Set #" << iT << "\n";
		cout << "The minimum number of moves is " << iAns << ".\n";
		++iT;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iT;
	cin >> iN >> iT;

	vector<int> vecAmount(iT + 1, 0);
	int iSum = 0;

	for (int i = 0;i < iN;++i)
	{
		int iD, iM;
		cin >> iD >> iM;
		iSum += iM;

		for (int t = iT;t >= iD;--t)
		{
			vecAmount[t] = max(vecAmount[t], vecAmount[t - iD] + iM);
		}
	}
	
	cout << (iSum - vecAmount[iT]) << "\n";
	return 0;
}

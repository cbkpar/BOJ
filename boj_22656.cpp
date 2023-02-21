#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iM, iP;
		cin >> iN >> iM >> iP;
		if (iN == 0 && iM == 0 && iP == 0) break;

		int iSum = 0;
		vector<int> vecNum(iN);
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecNum[i];
			iSum += vecNum[i];
		}
		if (vecNum[iM - 1] == 0)
		{
			cout << "0\n";
		}
		else
		{
			cout << (iSum) * (100 - iP) / vecNum[iM - 1] << "\n";
		}
	}

	return 0;
}

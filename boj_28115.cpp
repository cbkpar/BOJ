#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<long long> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	bool bPossible = true;
	for (int i = 2; i < iN; ++i)
	{
		if (vecNum[i - 1] - vecNum[i - 2] != vecNum[i] - vecNum[i - 1])
		{
			bPossible = false;
		}
	}
	if (!bPossible)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		long long lDiff = 0;
		if (iN >= 2)
		{
			lDiff = vecNum[1] - vecNum[0];
		}
		for (int i = 0; i < iN; ++i)
		{
			cout << vecNum[0] << (i == iN - 1 ? "\n" : " ");
		}
		for (int i = 0; i < iN; ++i)
		{
			cout << (lDiff * i) << (i == iN - 1 ? "\n" : " ");
		}
	}
	return 0;
}

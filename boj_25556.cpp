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
	vector<int> vecNum(iN);
	vector<bool> vecUsed(iN, false);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	for (int k = 0; k < 4; ++k)
	{
		int iMax = -1;
		for (int i = 0; i < iN; ++i)
		{
			if (!vecUsed[i] && vecNum[i] > iMax)
			{
				iMax = vecNum[i];
				vecUsed[i] = true;
			}
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		if (!vecUsed[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}

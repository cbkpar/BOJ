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

	vector<int> vecCount(100001, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCount[iNum];
	}

	bool bPossible = true;
	for (int i = 1; i <= 100000; ++i)
	{
		if (vecCount[i] * 2 > iN + 1)
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "YES" : "NO") << "\n";
	return 0;
}

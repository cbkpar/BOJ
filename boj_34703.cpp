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

	vector<bool> vecUsed(6, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iDay;
		cin >> iDay;
		vecUsed[iDay] = true;
	}

	bool bPossible = false;
	for (int i = 1; i <= 5; ++i)
	{
		if (!vecUsed[i])
		{
			bPossible = true;
		}
	}

	cout << (bPossible ? "YES" : "NO") << "\n";
	return 0;
}

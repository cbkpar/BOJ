#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iM >> iN;

	vector<int> vecCount(iM + 2, 0);
	for (int i = 0;i < iN;++i)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecCount[iS]++;
		vecCount[iE + 1]--;
	}

	for (int i = 1;i <= iM + 1;++i)
	{
		vecCount[i] += vecCount[i - 1];
	}

	int iCount = 0;
	for (int i = 1;i <= iM;++i)
	{
		if (vecCount[i] > 0)
		{
			++iCount;
		}
	}

	if (iCount == iM)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}

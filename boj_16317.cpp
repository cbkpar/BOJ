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
	vector<bool> vecDay(366, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iDay;
		cin >> iDay;
		vecDay[iDay] = true;
	}

	int iCount = 0;
	int iTotal = 0;
	int iAns = 0;
	for (int i = 1; i <= 365; ++i)
	{
		if (vecDay[i])
		{
			++iCount;
		}
		iTotal += iCount;
		if (iTotal >= 20)
		{
			iCount = 0;
			iTotal = 0;
			++iAns;
		}
	}

	if (iCount > 0) ++iAns;
	cout << iAns << "\n";
	return 0;
}

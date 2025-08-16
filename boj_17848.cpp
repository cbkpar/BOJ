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
	cin >> iN >> iM;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	int iNow = iM;
	while (vecNum[iNow] != iM)
	{
		iNow = vecNum[iNow];
		++iAns;
	}
	if (iAns > 0) ++iAns;

	cout << iAns << "\n";
	return 0;
}

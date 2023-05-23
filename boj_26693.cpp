#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecCount(121, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iScore;
		cin >> iScore;
		++vecCount[iScore];
	}

	int iSum = 0;
	for (int i = 120; i >= 0; --i)
	{
		iSum += vecCount[i];
		if (iSum >= iK) break;
	}

	cout << iSum << "\n";
	return 0;
}

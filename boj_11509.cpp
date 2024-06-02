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

	vector<int> vecCount(1000001, 0);

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;

		if (vecCount[iNum] > 0)
		{
			--vecCount[iNum];
			++vecCount[iNum - 1];
		}
		else
		{
			++vecCount[iNum - 1];
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}

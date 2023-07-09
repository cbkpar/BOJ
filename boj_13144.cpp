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
	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	long long lSum = 0;

	vector<int> vecCount(100001, 0);
	int iLeft = 0;
	for (int i = 0; i < iN; ++i)
	{
		++vecCount[vecNum[i]];
		while (vecCount[vecNum[i]] >= 2)
		{
			--vecCount[vecNum[iLeft]];
			++iLeft;
		}
		lSum += i - iLeft + 1;
	}
	cout << lSum << "\n";
	return 0;
}

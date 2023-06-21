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

	vector<long long> vecA(iN, 0);
	vector<long long> vecB(iN+1, 0);

	for (int i = 0; i < iN; ++i) cin >> vecA[i];
	for (int i = 0; i < iN; ++i) cin >> vecB[i];
	vecB[iN] = 1000000000000000001LL;

	for (int i = 0; i < iN; ++i)
	{
		int iLeft = 0;
		int iRight = iN;
		while (iLeft < iRight)
		{
			int iMid = (iLeft + iRight) >> 1;
			if (vecA[i] >= vecB[iMid])
			{
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid;
			}
		}
		cout << (iRight - i - 1) << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}

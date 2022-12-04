#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	long long* ArrExp = new long long[iN];
	memset(ArrExp, 0, sizeof(long long) * iN);

	long long lAns = 0;
	int iNowK = 0;
	for (int i = 0; i < iN; ++i)
	{
		cin >> ArrExp[i];
	}
	sort(ArrExp, ArrExp + iN);
	for (int i = 0; i < iN; ++i)
	{
		lAns += ArrExp[i] * iNowK;
		if (iNowK < iK) {
			++iNowK;
		}
	}
	cout << lAns << "\n";
	delete[] ArrExp;
	return 0;
}

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

	long long lNow = 1;
	for (int i = 0; i < iN; ++i)
	{
		lNow <<= 1;
		long long lNeed;
		cin >> lNeed;
		if (lNow < lNeed)
		{
			cout << "error\n";
			return 0;
		}
		lNow -= lNeed;
		if (lNow >= ((long long)1 << 62))
		{
			lNow %= 1000000007;
			lNow += 1000000007L * (((long long)1 << 61) / 1000000007L);
		}
	}
	cout << (lNow % 1000000007) << "\n";

	return 0;
}

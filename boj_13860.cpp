#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;

	long long lLength = 1;
	long long lRange = 1;
	long long lTotalRange = 1;
	while (true)
	{
		lRange *= 26;
		lTotalRange = lRange * lLength;
		if (lN >= lTotalRange)
		{
			lN -= lTotalRange;
			++lLength;
			continue;
		}
		long long lIndex = lN%lLength;
		lN /= lLength;
		vector<long long> vecNum(lLength, 0);
		for (long long i = 0; i < lLength; ++i)
		{
			lRange /= 26;
			vecNum[i] = lN / lRange;
			lN -= vecNum[i] * lRange;
		}
		cout << (char)(vecNum[lIndex] + 'A') << "\n";
		break;
	}
	return 0;
}

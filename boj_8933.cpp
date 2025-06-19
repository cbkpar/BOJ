#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN;
		string strWord;
		cin >> iN >> strWord;

		long long lMax = 0;
		long long lCount = 0;
		map<long long, long long> mapCount;

		int iLen = strWord.length();
		for (int i = 0;i < iN;++i)
		{
			if (strWord[i] == 'A') lCount += 1L;
			if (strWord[i] == 'G') lCount += 1L * 60001;
			if (strWord[i] == 'C') lCount += 1L * 60001 * 60001;
			if (strWord[i] == 'T') lCount += 1L * 60001 * 60001 * 60001;
		}
		mapCount[lCount] = 1;
		lMax = 1;
		for (int i = iN;i < iLen;++i)
		{
			if (strWord[i] == 'A') lCount += 1L;
			if (strWord[i] == 'G') lCount += 1L * 60001;
			if (strWord[i] == 'C') lCount += 1L * 60001 * 60001;
			if (strWord[i] == 'T') lCount += 1L * 60001 * 60001 * 60001;
			if (strWord[i-iN] == 'A') lCount -= 1L;
			if (strWord[i-iN] == 'G') lCount -= 1L * 60001;
			if (strWord[i-iN] == 'C') lCount -= 1L * 60001 * 60001;
			if (strWord[i-iN] == 'T') lCount -= 1L * 60001 * 60001 * 60001;

			if (++mapCount[lCount] > lMax)
			{
				lMax = mapCount[lCount];
			}
		}

		cout << lMax << "\n";
	}


	return 0;
}

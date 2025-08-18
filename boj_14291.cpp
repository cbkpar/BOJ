#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		string strLine;
		cin >> strLine;

		long long lBlue = 0;
		for (char ch : strLine)
		{
			if (ch == 'B')
			{
				++lBlue;
			}
		}

		long long lAns = 0;

		long long lA, lB;
		cin >> lA >> lB;
		--lA;
		--lB;

		long long lLen = strLine.length();

		long long lStart = lA / lLen;
		lA -= lStart * lLen;
		lB -= lStart * lLen;

		if (lB >= 2 * lLen)
		{
			long long lEnd = (lB / lLen) - 1;
			lB -= lEnd * lLen;
			lAns += lBlue * lEnd;
		}

		for (long long i = lA;i <= lB;++i)
		{
			if (strLine[i % lLen] == 'B')
			{
				++lAns;
			}
		}

		cout << "Case #" << t << ": " << lAns << "\n";
	}
	return 0;
}

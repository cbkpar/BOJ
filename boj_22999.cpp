#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iN, iK;
		cin >> iN >> iK;

		string strLine;
		cin >> strLine;

		int iCount = 0;
		for (int i = 0;i < iN / 2;++i)
		{
			if (strLine[i] != strLine[iN - i - 1])
			{
				++iCount;
			}
		}
		int iAns = abs(iCount - iK);
		cout << "Case #" << t << ": " << iAns << "\n";
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 0;t < iT;++t)
	{
		int iStart = 0;
		cin >> iStart;
		int iAns = 0;
		while (true)
		{
			int iNum;
			cin >> iNum;
			if (iNum == 0) break;
			if (iNum > iStart * 2)
			{
				iAns += iNum - iStart * 2;
			}
			iStart = iNum;
		}
		cout << iAns << "\n";
	}

	return 0;
}

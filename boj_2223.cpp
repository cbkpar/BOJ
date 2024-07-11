#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT, iX, iM;
	cin >> iT >> iX >> iM;

	int iMin = 1000000000;
	for (int i = 0;i < iM;++i)
	{
		int iD, iS;
		cin >> iD >> iS;

		iMin = min(iMin, (iD + iS - 1) / iS);
	}

	if (iMin <= 1)
	{
		cout << "0" << "\n";
		return 0;
	}

	int iAns = 0;

	while (iT-- > 0)
	{
		if (iMin <= 1)
		{
			++iMin;
		}
		else
		{
			iAns += iX;
			--iMin;
		}
	}

	cout << iAns << "\n";
	return 0;
}

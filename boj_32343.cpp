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

	int iA, iB;
	cin >> iA >> iB;

	int iAns = 0;
	if (iA + iB > iN)
	{
		int iC = iN - (iA + iB - iN);
		for (int i = 0;i < iC;++i)
		{
			iAns += 1 << (iN - 1 - i);
		}
	}
	else
	{
		for (int i = 0;i < iA + iB;++i)
		{
			iAns += 1 << (iN-1-i);
		}
	}

	cout << iAns << "\n";
	return 0;
}

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

	vector<bool> vecDislike(101, false);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vecDislike[iNum] = true;
	}

	int iAns = 0;

	int iM;
	cin >> iM;
	while (iM--)
	{
		bool bLike = true;
		int iCount;
		cin >> iCount;

		while (iCount--)
		{
			int iNum;
			cin >> iNum;
			if (vecDislike[iNum])
			{
				bLike = false;
			}
		}

		if (bLike)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}

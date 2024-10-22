#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mapCount[1001][1001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB;
	cin >> iA >> iB;

	int iR;
	cin >> iR;

	int iAns = 0;
	while (true)
	{
		if (++mapCount[iA][iB] == 2)
		{
			break;
		}

		if (iA + iB + 2 < iR)
		{
			iA += 1;
			iB += 1;
		}
		else
		{
			iA /= 2;
			iB /= 2;
		}

		++iAns;
	}

	cout << iAns << "\n";
	return 0;
}

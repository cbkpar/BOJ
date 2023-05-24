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
	for (int t = 1; t <= iT; ++t)
	{
		int iX = 0;
		int iY = 0;

		int iAnsDist = 0;
		int iAnsX = 0;
		int iAnsY = 0;
		while (true)
		{
			int iDiffX, iDiffY;
			cin >> iDiffX >> iDiffY;
			if (iDiffX == 0 && iDiffY == 0) break;
			iX += iDiffX;
			iY += iDiffY;
			int iDist = iX * iX + iY * iY;
			if (iDist > iAnsDist)
			{
				iAnsDist = iDist;
				iAnsX = iX;
				iAnsY = iY;
			}
			else if (iDist == iAnsDist)
			{
				if (iX > iAnsX)
				{
					iAnsX = iX;
					iAnsY = iY;
				}
			}
		}
		cout << iAnsX << " " << iAnsY << "\n";
	}
	return 0;
}

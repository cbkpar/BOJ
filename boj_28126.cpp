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

	int iN;
	cin >> iN;
	string strCommand;
	cin >> strCommand;

	int iU = 0;
	int iR = 0;
	int iX = 0;

	for (char ch : strCommand)
	{
		if (ch == 'U') ++iU;
		if (ch == 'R') ++iR;
		if (ch == 'X') ++iX;
	}

	int iAns = 0;
	int iM;
	cin >> iM;
	while (iM--)
	{
		int iPosX, iPosY;
		cin >> iPosX >> iPosY;
		--iPosX;
		--iPosY;

		int iMinX = min(iX, min(iPosX, iPosY));
		iPosX -= iMinX + iR;
		iPosY -= iMinX + iU;
		if (iPosX <= 0 && iPosY <= 0)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}

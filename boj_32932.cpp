#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int matPos[1001][1001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	for (int i = 0;i < iN;++i)
	{
		int iX, iY;
		cin >> iX >> iY;
		matPos[iX + 500][iY + 500] = 1;
	}

	int iNowX = 0;
	int iNowY = 0;

	string strCmd;
	cin >> strCmd;

	for (char ch : strCmd)
	{
		if (ch == 'U' && matPos[iNowX + 500][iNowY + 501] == 0) ++iNowY;
		if (ch == 'D' && matPos[iNowX + 500][iNowY + 499] == 0) --iNowY;
		if (ch == 'R' && matPos[iNowX + 501][iNowY + 500] == 0) ++iNowX;
		if (ch == 'L' && matPos[iNowX + 499][iNowY + 500] == 0) --iNowX;
	}
	cout << iNowX << " " << iNowY << "\n";
	return 0;
}

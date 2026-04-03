#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dR[4] = { 0,-1,0,1 };
int dC[4] = { 1,0,-1,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iX = 0;
	int iY = 0;
	int iDir = 0;

	int iN;
	cin >> iN;

	int iT;
	cin >> iT;

	int iTime = 0;
	for (int i = 0;i < iN;++i)
	{
		int iNextTime;
		cin >> iNextTime;

		int iDiff = iNextTime - iTime;
		iX += dC[iDir] * iDiff;
		iY += dR[iDir] * iDiff;

		string strDir;
		cin >> strDir;
		if (strDir == "right")
		{
			iDir = (iDir + 1) % 4;
		}
		else if (strDir == "left")
		{
			iDir = (iDir + 3) % 4;
		}

		iTime = iNextTime;
	}
	iX += dC[iDir] * (iT - iTime);
	iY += dR[iDir] * (iT - iTime);
	cout << iX << " " << iY << "\n";
	return 0;
}

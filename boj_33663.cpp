#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iH1, iH2, iS1, iS2, iV1, iV2;
	cin >> iH1 >> iH2 >> iS1 >> iS2 >> iV1 >> iV2;

	int iR, iG, iB;
	cin >> iR >> iG >> iB;

	int iMax = max(iR, max(iG, iB));
	int iMin = min(iR, min(iG, iB));

	bool bPossible = true;
	if (iMax < iV1 || iMax > iV2) bPossible = false;
	if (255 * (iMax - iMin) < iS1 * iMax || 255 * (iMax - iMin) > iS2 * iMax) bPossible = false;

	double dH = 0.0;
	if (iMax == iR)
	{
		dH = 60.0 * (iG - iB) / (iMax - iMin);
	}
	else if (iMax == iG)
	{
		dH = 120 + 60.0 * (iB - iR) / (iMax - iMin);
	}
	else if (iMax == iB)
	{
		dH = 240 + 60.0 * (iR - iG) / (iMax - iMin);
	}
	if (dH < 0) dH += 360;
	if (dH < iH1 || dH > iH2) bPossible = false;

	if (bPossible)
	{
		cout << "Lumi will like it." << "\n";
	}
	else
	{
		cout << "Lumi will not like it." << "\n";
	}
	return 0;
}

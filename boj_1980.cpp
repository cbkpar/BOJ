#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iT;
	cin >> iN >> iM >> iT;

	int iHam = -1;
	int iCoke = iT + 1;

	int iCount = iT / iN;
	for (int i = 0; i <= iCount; ++i)
	{
		int iTotalHam = i + (iT - i * iN) / iM;
		int iTotalCoke = (iT - i * iN) % iM;
		if (iTotalCoke == iCoke)
		{
			iHam = max(iHam, iTotalHam);
		}
		else if (iTotalCoke < iCoke)
		{
			iCoke = iTotalCoke;
			iHam = iTotalHam;
		}
	}
	cout << iHam << " " << iCoke << "\n";
	return 0;
}

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
	while (iN--)
	{
		int iTA, iTB, iVA, iVB;
		cin >> iTA >> iTB >> iVA >> iVB;

		int iTime = iTB * iVB;
		iVA -= iTime / iTA;
		int iRemain = iTime % iTA;
		if (iVA > 0)
		{
			if (iVA % 2 == 0)
			{
				iTime += iVA / 2 * iTA;
			}
			else
			{
				iTime += iTA - iRemain;
				iTime += iVA / 2 * iTA;
			}
		}
		cout << iTime << "\n";

	}

	return 0;
}

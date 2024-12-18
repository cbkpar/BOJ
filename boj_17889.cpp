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

	int iY = 2018;
	int iM = 4;
	
	bool bPossible = false;
	while (iY <= iN)
	{
		if (iY == iN)
		{
			bPossible = true;
		}
		iY += 2;
		iM += 2;
		if (iM > 12)
		{
			iM -= 12;
			iY += 1;
		}
	}

	cout << (bPossible ? "yes" : "no") << "\n";
	return 0;
}

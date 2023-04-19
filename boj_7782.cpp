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

	int iPosX, iPosY;
	cin >> iPosX >> iPosY;

	bool bPossible = false;
	for (int i = 0; i < iN; ++i)
	{
		int iX1, iY1, iX2, iY2;
		cin >> iX1 >> iY1 >> iX2 >> iY2;
		if (iX1 <= iPosX && iPosX <= iX2 && iX1 <= iPosY && iPosY <= iY2)
		{
			bPossible = true;
		}
	}
	cout << (bPossible ? "Yes\n" : "No\n");
	return 0;
}

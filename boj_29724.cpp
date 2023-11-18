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

	int iWeight = 0;
	int iMoney = 0;

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strType;
		cin >> strType;

		int iW, iH, iL;
		cin >> iW >> iH >> iL;

		if (strType == "A")
		{
			int iCount = (iW / 12) * (iH / 12) * (iL / 12);
			iWeight += 1000 + iCount * 500;
			iMoney += 4000 * iCount;
		}
		else
		{
			iWeight += 6000;
		}
	}

	cout << iWeight << "\n";
	cout << iMoney << "\n";
	return 0;
}

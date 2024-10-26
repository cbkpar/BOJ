#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iC, iP;
		cin >> iC >> iP;

		map<string, int> mapMenu;
		for (int i = 0; i < iC; ++i)
		{
			string strMenu;
			cin >> strMenu;
			int iSmall, iMiddle, iLarge;
			cin >> iSmall >> iMiddle >> iLarge;

			mapMenu.insert({ strMenu + "_small",iSmall });
			mapMenu.insert({ strMenu + "_medium",iMiddle });
			mapMenu.insert({ strMenu + "_large",iLarge });
		}

		for (int i = 0; i < iP; ++i)
		{
			string strName;
			cin >> strName;

			string strSize, strMenu;
			cin >> strSize >> strMenu;

			int iSum = 100 / iP;
			iSum += mapMenu.find(strMenu + "_" + strSize)->second;

			if (iSum % 5 == 4)
			{
				++iSum;
			}
			if (iSum % 5 == 1)
			{
				--iSum;
			}
			cout << strName << " " << iSum << "\n";
		}
	}
	return 0;
}

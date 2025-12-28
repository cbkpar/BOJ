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

	int iT;
	cin >> iT;
	for (int t = 0; t < iT; ++t)
	{
		int iN;
		cin >> iN;

		int iSum = 0;
		for (int i = 0; i < iN * 2 + 1; ++i)
		{
			string strDigit;
			cin >> strDigit;
			if (i % 2 == 0)
			{
				if (strDigit == "!")
				{
					iSum += 10;
				}
				else
				{
					iSum += strDigit[0] - '0';
				}
			}
		}

		if (iSum >= 10)
		{
			cout << "!" << "\n";
		}
		else
		{
			cout << iSum << "\n";
		}
	}
	return 0;
}

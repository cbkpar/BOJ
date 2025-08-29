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

	int iAns = 1;
	int iAnsNum = 1;

	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		int iTemp = iNum;
		int iMax = 1;
		for (int j = 2;j <= iTemp;++j)
		{
			while (iTemp % j == 0)
			{
				iMax = j;
				iTemp /= j;
			}
		}
		if (iMax > iAns)
		{
			iAns = iMax;
			iAnsNum = iNum;
		}
	}

	cout << iAnsNum << "\n";
	return 0;
}

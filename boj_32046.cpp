#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0)  break;

		int iSum = 0;
		for (int i = 0;i < iN;++i)
		{
			int iCost;
			cin >> iCost;

			if (iSum + iCost <= 300)
			{
				iSum += iCost;
			}
		}
		cout << iSum << "\n";
	}

	return 0;
}

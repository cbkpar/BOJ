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
		int iN, iM;
		cin >> iN >> iM;

		if (iN == 0 && iM == 0) break;

		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}
		int iAns = -1;
		for (int i = 0;i < iN;++i)
		{
			for (int j = i + 1;j < iN;++j)
			{
				if (vecNum[i] + vecNum[j] <= iM)
				{
					iAns = max(iAns, vecNum[i] + vecNum[j]);
				}
			}
		}

		if (iAns == -1)
		{
			cout << "NONE" << "\n";
		}
		else
		{
			cout << iAns << "\n";
		}
	}


	return 0;
}

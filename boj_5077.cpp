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
	while (iT-- > 0)
	{
		int iR, iC;
		cin >> iR >> iC;
		vector<string> vecSecret(iR, "");
		for (int i = 0;i < iR;++i)
		{
			cin >> vecSecret[i];
		}

		int iN, iM;
		cin >> iN >> iM;
		vector<string> vecMap(iN, "");
		for (int i = 0;i < iN;++i)
		{
			cin >> vecMap[i];
		}

		int iAns = 0;
		for (int i = 0;i <= iN - iR;++i)
		{
			for (int j = 0;j <= iM - iC;++j)
			{
				bool bPossible = true;
				for (int p = 0;p < iR;++p)
				{
					for (int q = 0;q < iC;++q)
					{
						if (vecMap[i + p][j + q] != vecSecret[p][q])
						{
							bPossible = false;
						}
					}
				}
				if (bPossible)
				{
					++iAns;
				}
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}

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

	vector<int> vecNum(iN * 2, 0);
	for (int i = 0;i < iN * 2;++i)
	{
		vecNum[i] = i + 1;
	}

	int iM;
	cin >> iM;
	vector<int> vecTemp(iN * 2, 0);
	while (iM-- > 0)
	{
		int iK;
		cin >> iK;

		if (iK == 0)
		{
			for (int i = 0;i < iN;++i)
			{
				vecTemp[i * 2] = vecNum[i];
				vecTemp[i * 2 + 1] = vecNum[i + iN];
			}
		}
		else
		{
			for (int i = 0;i < 2 * iN;++i)
			{
				vecTemp[i] = vecNum[(iK + i) % (2 * iN)];
			}
		}

		for (int i = 0;i < iN * 2;++i)
		{
			vecNum[i] = vecTemp[i];
		}
	}

	for (int i = 0;i < iN * 2;++i)
	{
		cout << vecNum[i] << "\n";
	}
	return 0;
}

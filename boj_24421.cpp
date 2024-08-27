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
	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		for (int j = i + 1;j < iN;++j)
		{
			for (int k = j + 1;k < iN;++k)
			{
				if (vecNum[i] * vecNum[j] == vecNum[k])
				{
					++iAns;
				}
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}

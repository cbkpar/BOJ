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

	vector<int> vecRank(iN, 1);
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			if (vecNum[j] < vecNum[i])
			{
				++vecRank[i];
			}
		}
	}

	for (int i = 0;i < iN;++i)
	{
		cout << vecRank[i] << "\n";
	}
	return 0;
}

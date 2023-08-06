#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(10, 0);
	for (int i = 0; i < 10; ++i) cin >> vecNum[i];

	int iAns = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = i + 1; j < 10; ++j)
		{
			int iTemp = vecNum[i] || vecNum[j];
			iAns ^= iTemp;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = i + 1; j < 10; ++j)
		{
			for (int k = j + 1; k < 10; ++k)
			{
				int iTemp = vecNum[i] || vecNum[j] || vecNum[k];
				iAns ^= iTemp;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}

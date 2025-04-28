#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}

		int iAns = 0;
		for (int i = 0;i < iN - 1;++i)
		{
			int iTemp = vecNum[i];
			int iIndex = i;
			for (int j = i + 1;j < iN;++j)
			{
				if (vecNum[j] < iTemp)
				{
					iTemp = vecNum[j];
					iIndex = j;
				}
			}
			iAns += iIndex - i + 1;
			for (int j = i;j < iIndex-(j-i);++j)
			{
				swap(vecNum[j], vecNum[iIndex-(j-i)]);
			}
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}

	return 0;
}

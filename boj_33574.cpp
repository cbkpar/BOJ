#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> vecNum(3000, 0);

	int iSize = 0;

	int iQ;
	cin >> iQ;
	while (iQ-- > 0)
	{
		int iCommand;
		cin >> iCommand;

		if (iCommand == 1)
		{
			int iX;
			cin >> iX;
			if (iX == 1)
			{
				sort(vecNum.begin(), vecNum.begin() + iSize);
			}
			else
			{
				sort(vecNum.begin(), vecNum.begin() + iSize, greater<int>());
			}
		}
		else
		{
			int iX, iT;
			cin >> iX >> iT;
			++iSize;
			for (int i = iSize;i > iX;--i)
			{
				vecNum[i] = vecNum[i - 1];
			}
			vecNum[iX] = iT;
		}
	}

	cout << iSize << "\n";
	if (iSize > 0)
	{
		for (int i = 0;i < iSize;++i)
		{
			cout << vecNum[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}
	return 0;
}

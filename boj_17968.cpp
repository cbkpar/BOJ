#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(1001, 0);
	vecNum[0] = 1;
	vecNum[1] = 1;

	for (int i = 2;i <= 1000;++i)
	{
		vecNum[i] = 1;
		int iIndex = 0;
		bool bPossible = true;
		while (true)
		{
			++iIndex;
			if (i - 2 * iIndex < 0)
			{
				if (bPossible)
				{
					break;
				}
				else
				{
					++vecNum[i];
					iIndex = 0;
					bPossible = true;
					continue;
				}
			}
			if (vecNum[i] - vecNum[i - iIndex] == vecNum[i - iIndex] - vecNum[i - iIndex * 2])
			{
				bPossible = false;
			}
		}
		
	}

	int iN;
	cin >> iN;
	cout << vecNum[iN] << "\n";
	return 0;
}

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
	vector<int> vecCount(25, 0);

	for (int i = 0; i < iN; ++i)
	{
		vector<int> vecNum(5, 0);
		for (int j = 0; j < 5; ++j)
		{
			cin >> vecNum[j];
		}
		for (int j = 0; j < 5; ++j)
		{
			for (int k = j + 1; k < 5; ++k)
			{
				if (vecNum[j] == 1 && vecNum[k] == 1)
				{
					++vecCount[j * 5 + k];
				}
			}
		}
	}

	int iAns = 5;
	int iMax = 0;
	for (int i = 0; i < 25; ++i)
	{
		if (iMax < vecCount[i])
		{
			iAns = i;
			iMax = vecCount[i];
		}
	}

	vector<int> vecAns(5, 0);
	vecAns[iAns / 5] = 1;
	vecAns[iAns % 5] = 1;

	cout << iMax << "\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << vecAns[i] << (i == 4 ? "\n" : " ");
	}
	return 0;
}

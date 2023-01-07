#include <iostream>

using namespace std;

int arrNumber[20] = { 0, };
bool bVisited[11][10001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iS, iE;
	cin >> iS >> iE;

	for (int i = 0; i < iS; ++i)
	{
		cin >> arrNumber[i];
	}
	bVisited[0][0] = true;
	for (int i = 0; i < iE; ++i)
	{
		for (int j = 0; j <= 10000; ++j)
		{
			if (bVisited[i][j])
			{
				bVisited[i + 1][j] = true;
				for (int k = 0; k < iS; ++k)
				{
					if (j + arrNumber[k] <= 10000)
					{
						bVisited[i + 1][j + arrNumber[k]] = true;
					}
				}
			}
		}
	}
	int iCount = 0;
	int iMax = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		if (bVisited[iE][i])
		{
			++iCount;
		}
		else
		{
			iCount = 0;
		}
		if (iMax < iCount)
		{
			iMax = iCount;
		}
	}
	cout << iMax << "\n";

	return 0;
}

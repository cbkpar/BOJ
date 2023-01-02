#include <iostream>

using namespace std;

int mapNumber[1001][1001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iR1, iC1, iR2, iC2;
	iR1 = iC1 = iR2 = iC2 = 0;
	bool bFirst = true;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> mapNumber[i][j];
			if (mapNumber[i][j] == 2 || mapNumber[i][j] == 5)
			{
				if (bFirst)
				{
					iR1 = i;
					iC1 = j;
					bFirst = false;
				}
				else
				{
					iR2 = i;
					iC2 = j;
				}
			}
		}
	}
	int iStudent = 0;
	int iMinR = iR1 < iR2 ? iR1 : iR2;
	int iMaxR = iR1 > iR2 ? iR1 : iR2;
	int iMinC = iC1 < iC2 ? iC1 : iC2;
	int iMaxC = iC1 > iC2 ? iC1 : iC2;
	for (int i = iMinR; i <= iMaxR; ++i)
	{
		for (int j = iMinC; j <= iMaxC; ++j)
		{
			if (mapNumber[i][j] == 1)
			{
				++iStudent;
			}
		}
	}
	if ((iR1 - iR2) * (iR1 - iR2) + (iC1 - iC2) * (iC1 - iC2) >= 25 && iStudent >= 3)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
	return 0;
}
